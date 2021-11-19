/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date November 21, 2014

        @version 0.4

*/
/**
        @file

        @brief

        @detail

*/
#ifndef ETISS_PLUGIN_VIRTUALSTRUCT_H_
#define ETISS_PLUGIN_VIRTUALSTRUCT_H_
#include "etiss/CVirtualStruct.h"
#include "etiss/Misc.h"
#include "etiss/fault/Injector.h"

#include <cstddef>

#include <memory>

namespace etiss
{

class VSSync;

/**
    abstract representation of an module of a simulation which could be a embedded device of the cpu of an embedded
device. it is recommended to model and address the full hardware hierachy. e.g. <pre> device1
            -> cpu
                -> cache
            -> bus
            -> memory
                -> bank1
                -> bank2

        example address: "device1::cpu::cache"
    </pre>
    To resolve a path to a VirtualStruct use
VirtualStruct::root()->getVirtualStruct("device1::cpu::cache");

    Fields of a VirtualStruct can be addressed by appending ".FIELDNAME" to the
pass and pass it to getResolvedField(). e.g.
VirtualStruct::root()->getResolvedField("device1::cpu::cache.tag1");

<pre>
<b>Syntax (Wirth syntax notation):</b>

    module_path_to_field:   module_path "." { ASCII-character }
    module_path:            module_name { "::" module_name } .
    module_name:            letter { digit | letter } .
    letter:                 "a" | "A" | "b" | "B" | <b>...</b> | "z" | "Z" .
    digit:                  "0" | "1" | "2" | "3" | "4" | "5" | "6" | 7" | "8" |
"9" .

    module_path_to_field is the full path to a field.
    module_path is always relative to the current module

EXTENSION for absolute paths:

    absolute_module_path_to_field:  "::" module_path_to_field
    absolute_module_path:           "::" module_path .

    absolute module path will NOT use root()!
        it will traverse from the current module upward until no parent exists
and then the path will be resolved


</pre>

    the tree of modules uses weak/shared pointers to create a tree that will clean itself up as soon as possible
depending on the lifetime of the virtual structs that were associated with said module.

    weak reference: --> ( x holds a weak reference to y [x.weak_ptr = y])
    strong reference: x -> y ( x holds a strong reference to y [x.shared_ptr =
y])

<pre>
Relations:

    VirtualStruct
        --> <- VirtualStruct
            --> <- VirtualStruct

    VirtualStruct holds a weak reference to child VirtualStructs and a child VirtualStruct holds a strong reference to
VirtualStruct. Module holds a weak reference to a child Module and a child Module holds a strong reference to parent
Module VirtualStructs are deleted if the original shared_ptr is deleted, there is no child and there is no shared_ptr to
a field




</pre>

@attention: while VirtualStruct won't throw exceptions by itself, VirtualStruct::Field will throw exception upon invalid
access or if the associated VirtualStruct has been closed

*/
class VirtualStruct : public std::enable_shared_from_this<VirtualStruct>, public etiss::fault::Injector
{
    friend class VSSync;

  public:
    /**
        a Field instance represents e.g. a field in a structure, a variable/register in a model or anything that can be
       represented as a sequence of up to 64 bits
    */
    class Field
    {
      public:
        /**
                NOTE: etiss::CPUArch should implement support for Listeners by either using the
           etiss::VirtualStruct::Field instance to write to listener supported field or it should call the signalWrite()
           functions of a Field \attention Listeners should be very carefull or infinite recursion if they write to a
           field within the write call.
        */
        class Listener
        {
          public:
            virtual ~Listener();
            virtual void write(etiss::VirtualStruct::Field &field, uint64_t val) = 0;
        };

      private:
        struct listener_pair_compare
        {
            bool operator()(const std::pair<Listener *, std::shared_ptr<Listener>> &lhs,
                            const std::pair<Listener *, std::shared_ptr<Listener>> &rhs) const
            {
                return lhs.first < rhs.first;
            }
        };

      public:
        /**
        defines how a field should perform reads/writes. default: PREFER_LAMBDA
        */
        enum AccessMode
        {
            /// uses the virtual _read() / _write functions
            VIRTUAL,
            /// uses the lread,lwrite functions
            LAMBDA,
            /// tries to use the lread,lwrite functions and falls back to virtual
            /// functions
            PREFER_LAMBDA,
        };

      public:                        // flags
        static const int R = 1;      ///< read flag
        static const int W = 2;      ///< write flag
        static const int RW = R | W; ///< flags to signal that a field supports read and write operations
        static const int L = 4;      ///< supports listener plugins; used for etiss::RegisterDevicePlugins to determine
                                     ///< access to a variable/field
        static const int F = 8;      ///< supports fault injection/tracing
        static const int A = 16;     ///< supports advanced fault injection/tracing with the applyAction function
        static const int P = 32; ///< private field: this flag indicates that this field is an implementation specific
                                 ///< field that e.g. is not to be copied by etiss::copy()

      public: // constructor
        /**
        @param width width of the field in bytes. rounded up in case of bitwidth
        missmatch
        @param bitwidth width of the field in bits. if 0 then width*8 will be used
        for bitwidth_
        */
        Field(VirtualStruct &parent, const std::string &name, const std::string &prettyname, int flags, size_t width,
              size_t bitwidth = 0);
        Field(VirtualStruct &parent, const std::string &name, const std::string &prettyname, int flags, size_t width,
              bool virtual_enabled, std::function<uint64_t()> lread, std::function<void(uint64_t)> lwrite,
              size_t bitwidth = 0);
        virtual ~Field();

      public:                    // fields
        VirtualStruct &parent_;  ///< reference to parent virtual struct
        const std::string name_; ///< name of the field. should be a simple/easy to parse name. e.g. representing the
                                 ///< "SR" OR1K CPU register: SPR[0][17]
        const std::string prettyname_; ///< alternative/human readable name of the field. e.g. representing the "SR"
                                       ///< OR1K CPU register: "SR" or "SupervisorRegister"
        int flags_;             ///< read write flags as specified by the static const int parameters of Field: R,W,L
        const size_t width_;    ///< width in bytes (rounded up if neccessary)
        const size_t bitwidth_; ///< width in bits
        const AccessMode accessMode_;

      public: // read write
        uint64_t read()
            const; ///< function to read bits/a value from the Field. may only be called if the R flag is set. in case
                   ///< of less than 64 bit values the msb should be extended according to the default c++ conversion
                   ///< behavior. e.g. int32_t read_value = X; return (uint64_t)read_value;
        void write(uint64_t); ///< function to write bits/a value to the Field. may only be called if the W flag is set.
                              ///< additional bits are silently discarded if the targt field has less than 64 bits. e.g.
                              ///< int64_t write_target = (int32_t) write_uint64_t;
        bool applyBitflip(unsigned position, uint64_t fault_id); ///< function to write a bitflip to a field
        bool applyAction(const etiss::fault::Fault &f, const etiss::fault::Action &a,
                         std::string &errormsg); ///< advanced fault injection. Field must have the A flag to use this.
        void signalWrite(); ///< this function should be called if the listener flag is set and the field changed
                            ///< without using the write() function. write() will automatically call this function if
                            ///< the listener flag is set.
      protected:            // read write implementation
        /// override this function to implement reads in case of AccessMode::VIRTUAL / AccessMode::PREFER_LAMBDA
        virtual uint64_t _read() const;
        /// override this function to implement writes in case of
        /// AccessMode::VIRTUAL / AccessMode::PREFER_LAMBDA
        virtual void _write(uint64_t);
        /// override this function to implement bitflip applying to a field
        virtual bool _applyBitflip(unsigned position, uint64_t fault_id);
        /// override this function to implement advanced action handling
        virtual bool _applyAction(const etiss::fault::Fault &f, const etiss::fault::Action &a, std::string &errormsg);
        /// set this function for reads in case of AccessMode::LAMBDA / AccessMode::PREFER_LAMBDA
        std::function<uint64_t()> lread;
        /// set this function for writes in case of AccessMode::LAMBDA /
        /// AccessMode::PREFER_LAMBDA
        std::function<void(uint64_t)> lwrite;

      public:
        /// if this function is set the the default implementation of applyBitflip will use it
        std::function<bool(unsigned position, uint64_t fault_id)> lapplyBitflip;

      public:
        std::function<void(Field *)> delete_;
        inline Field *setDeleteP(std::function<void(Field *)> del)
        {
            delete_ = del;
            return this;
        }
        inline Field &setDelete(std::function<void(Field *)> del)
        {
            delete_ = del;
            return *this;
        }

      public:
        /**
                @param ref optional reference that is stored alongside the pointer
        */
        bool addListener(Listener *listener, std::shared_ptr<Listener> ref = nullptr);
        /**
                @param ref is ignored and can therfore be null. NEVER write new std::shared_ptr<Listener>(YOURPOINTER)
           after a shared pointer was already created
        */
        void removeListener(Listener *listener, std::shared_ptr<Listener> ref = nullptr);

      private:
        std::set<std::pair<Listener *, std::shared_ptr<Listener>>, listener_pair_compare> listeners;
    };

  private:
    template <typename structT, typename retT, retT structT::*field>
    class FieldT : public VirtualStruct::Field
    {
        static_assert(sizeof(retT) <= sizeof(uint64_t),
                      "Cannot use etiss::VirtualStruct::FieldT for a field larger than uint64_t");

      protected:
        FieldT(VirtualStruct &parent, const std::string &name, const std::string &prettyname)
            : Field(parent, name, prettyname, 0, sizeof(retT))
        {
        }
        virtual uint64_t _read() const { return (uint64_t)((const structT *)parent_.structure_)->*field; }
        virtual void _write(uint64_t val) { ((structT *)parent_.structure_)->*field = (retT)val; }
    };

  private:
    VirtualStruct(void *structure, std::function<void(Field *)> dtor = [](Field *f) { delete f; });

  public:
    virtual ~VirtualStruct();

    bool addField(Field *f, bool noerrorprint = false);

    template <typename structT, typename retT, retT structT::*field>
    /// add a structure field to this VirtualStructure
    bool addField(const std::string &name, const std::string &prettyname = "", bool noerrorprint = false)
    {

        Field *ret = new FieldT<structT, retT, field>(*this, name, prettyname);

        if (!addField(ret, noerrorprint))
        {
            delete ret;
            return false;
        }

        return true;
    }

    template <typename T>
    bool addField(const std::string &name, const std::string &prettyname, std::function<T()> read,
                  std::function<void(T)> write, bool supportsListener = false, bool noerrorprint = false)
    {
        int flags = 0;
        if (read)
            flags |= Field::R;
        if (write)
            flags |= Field::W;
        if (supportsListener)
            flags |= Field::L;
        Field *f = new Field(*this, name, prettyname, flags, sizeof(T), false, [read]() { return (uint64_t)read(); },
                             [write](uint64_t v) { write((T)v); });
        if (addField(f, noerrorprint))
            return true;
        delete f;
        return false;
    }

    std::shared_ptr<Field> findName(const std::string &name) const;
    std::shared_ptr<Field> findPrettyName(const std::string &name) const;
    void foreachField(const std::function<void(std::shared_ptr<Field>)> &func);

    bool mountStruct(const std::string &name, const std::shared_ptr<VirtualStruct> vs);
    std::shared_ptr<VirtualStruct> findStruct(const std::string &name);
    void foreachStruct(const std::function<void(const std::string &name, VirtualStruct &vs)> &func);

    void close();
    bool isClosed();

  public: // inherited from etiss::fault::Injector
    virtual std::list<std::string> listFields();
    virtual std::list<std::string> listSubInjectors();

    virtual std::shared_ptr<etiss::fault::Injector> getSubInjector(const std::string &name);
    virtual std::shared_ptr<etiss::fault::Injector> getParentInjector();

    virtual bool acceleratedTrigger(const etiss::fault::Trigger &, int32_t fault_id);

  protected: // inherited from etiss::fault::Injector
    virtual void *fastFieldAccessPtr(const std::string &name, std::string &errormsg);
    virtual bool readField(void *fastfieldaccessptr, uint64_t &val, std::string &errormsg);
    virtual bool applyAction(const etiss::fault::Fault &fault, const etiss::fault::Action &action,
                             std::string &errormsg);
    virtual bool update_field_access_rights(const std::string& field, etiss::fault::Action::Type type, std::string& errormsg);

  public:
    /// set this function to handle custom commands passed by etiss::fault::Action of the type
    /// etiss::fault::Action::COMMAND
    std::function<bool(const etiss::fault::Fault &, const etiss::fault::Action &, std::string & /*errormsg*/)>
        applyCustomAction;

  public:
    void *const structure_;
    std::function<bool(const etiss::fault::Trigger &, int32_t)> acceleratedTrigger_;

  private:
    std::list<Field *> fields_;
    std::map<std::string, Field *> fieldNames_;
    std::map<std::string, Field *> fieldPrettyNames_;
    std::map<std::string, std::weak_ptr<VirtualStruct>> subStructs_;
    std::function<void(Field *)> dtor_;
    bool closed;

  private:
    std::shared_ptr<VirtualStruct> parent_;

  public:
    static std::shared_ptr<VirtualStruct> allocate(void *structure, std::function<void(Field *)> delete_);

  public: // name resolving an root VirtualStruct
    static std::shared_ptr<VirtualStruct> root();

    std::shared_ptr<VirtualStruct> getVirtualStruct(const std::string &path);

    std::shared_ptr<VirtualStruct::Field> getResolvedField(const std::string &path);

  public: // C interface
    /**
        implemented in CVirtualStruct.cpp
    */
    static std::shared_ptr<VirtualStruct> allocateFromC(void *handle, VirtualStruct_names names,
                                                        VirtualStruct_prettyNames prettyNames_optional,
                                                        VirtualStruct_read read_recommended,
                                                        VirtualStruct_write write_optional,
                                                        VirtualStruct_setListenerCallback setListenerCallback_optional,
                                                        std::function<void(void *handle)> cleanup);
};

/**
    used for synchronization of the tree of virtual structs.
    @attention this cannot be used to synchronize field access
*/
class VSSync
{
  public:
    VSSync();
    ~VSSync();

  private:
    static std::recursive_mutex &mutex();
};

/**
        copies all fields with the same name from the source to the destination structure.
        if a source field is not present in the destination then the field will be added to dst_notPresent
        if a field is not writeable in the destination then the field will be added to dst_notWriteable
        if a destination field is not present in the source then the field will be added to dst_unknown
        if src_private and/or dst_private is passed then they will contain a list of private fields of the
   source/destination which are ignored by the copy function.
        @param pretend if true then no copy operation will be performed (only the lists will be filled)
*/
void copy(VirtualStruct &dst, VirtualStruct &src, std::list<std::shared_ptr<VirtualStruct::Field>> &dst_notPresent,
          std::list<std::shared_ptr<VirtualStruct::Field>> &dst_notWriteable,
          std::list<std::shared_ptr<VirtualStruct::Field>> dst_unknown, bool pretend = false,
          std::list<std::shared_ptr<VirtualStruct::Field>> *src_private = 0,
          std::list<std::shared_ptr<VirtualStruct::Field>> *dst_private = 0);

class VirtualStructSupport
{
  public:
    virtual inline ~VirtualStructSupport() {}
    /**
        @return may never be NULL
    */
    virtual std::shared_ptr<VirtualStruct> getStruct() = 0;
    virtual const std::string &getName() = 0;
};

#define ETISS_VIRTUALSTRUCT_ADDFIELD(VIRTUALSTRUCT, STRUCT, FIELD, NAME, PRETTYNAME) \
    (VIRTUALSTRUCT).addField<STRUCT, decltype(((STRUCT *)0)->FIELD), &STRUCT::FIELD>(NAME, PRETTYNAME);

} // namespace etiss

#endif
