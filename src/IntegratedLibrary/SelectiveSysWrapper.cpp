#include "etiss/IntegratedLibrary/SelectiveSysWrapper.h"
#include "etiss/ETISS.h"

namespace etiss
{
namespace plugin
{

struct WrapSystem
{
    ETISS_System sys;
    ETISS_System *orig;
    std::vector<void *> jitHandles;
};

ETISS_System *SelectiveSysWrapper::wrap(ETISS_CPU *cpu, ETISS_System *system)
{
    auto ret = new WrapSystem();
    ret->sys.handle = system->handle;
    ret->orig = system;

    auto jit = ((CPUCore *)cpu->_etiss_private_handle_)->getJIT();
    std::set<std::string> headers;
    headers.insert(etiss::jitFiles());
    std::string jitErr;

    auto makeWrapper = [&](void *funcPtr, void *handle, bool isDbg, bool isSync, bool isIRead)
    {
        std::string funcAddr = std::to_string((uintptr_t)funcPtr);
        std::string params, cast, call;
        params += "void *handle";
        cast += "void*";
        call += "(void*)" + std::to_string((uintptr_t)handle) + "ull";
        if (!isDbg)
        {
            params += ", ETISS_CPU *cpu";
            cast += ", ETISS_CPU*";
            call += ", cpu";
        }
        if (!isSync)
        {
            params += ", etiss_uint64 addr";
            cast += ", etiss_uint64";
            call += ", addr";
            if (!isIRead)
            {
                params += ", etiss_uint8 *buffer";
                cast += ", etiss_uint8*";
                call += ", buffer";
            }
            params += ", etiss_uint32 length";
            cast += ", etiss_uint32";
            call += ", length";
        }

        std::string code = "#include \"etiss/jit/System.h\"\n";
        code += "etiss_int32 wrapper(" + params + "){\n";
        code += "  return ((etiss_int32 (*)(" + cast + "))" + funcAddr + ")(" + call + ");\n}\n";

        void *jitHandle = jit->translate(code, headers, {}, {}, jitErr, false);
        ret->jitHandles.push_back(jitHandle);
        return jit->getFunction(jitHandle, "wrapper", jitErr);
    };

    ETISS_System wrapInfo = getWrapInfo(system);
    ret->sys = *system;
    if (wrapInfo.iread)
    {
        ret->sys.iread =
            (decltype(ret->sys.iread))makeWrapper((void *)wrapInfo.iread, wrapInfo.handle, false, false, true);
    }
    if (wrapInfo.iwrite)
    {
        ret->sys.iwrite =
            (decltype(ret->sys.iwrite))makeWrapper((void *)wrapInfo.iwrite, wrapInfo.handle, false, false, false);
    }
    if (wrapInfo.dread)
    {
        ret->sys.dread =
            (decltype(ret->sys.dread))makeWrapper((void *)wrapInfo.dread, wrapInfo.handle, false, false, false);
    }
    if (wrapInfo.dwrite)
    {
        ret->sys.dwrite =
            (decltype(ret->sys.dwrite))makeWrapper((void *)wrapInfo.dwrite, wrapInfo.handle, false, false, false);
    }
    if (wrapInfo.dbg_read)
    {
        ret->sys.dbg_read =
            (decltype(ret->sys.dbg_read))makeWrapper((void *)wrapInfo.dbg_read, wrapInfo.handle, true, false, false);
    }
    if (wrapInfo.dbg_write)
    {
        ret->sys.dbg_write =
            (decltype(ret->sys.dbg_write))makeWrapper((void *)wrapInfo.dbg_write, wrapInfo.handle, true, false, false);
    }
    if (wrapInfo.syncTime)
    {
        ret->sys.syncTime =
            (decltype(ret->sys.syncTime))makeWrapper((void *)wrapInfo.syncTime, wrapInfo.handle, false, true, false);
    }

    return (ETISS_System *)ret;
}

ETISS_System *SelectiveSysWrapper::unwrap(ETISS_CPU *cpu, ETISS_System *system)
{
    auto wrapSys = (WrapSystem *)system;
    auto jit = ((CPUCore *)cpu->_etiss_private_handle_)->getJIT();
    for (auto h : wrapSys->jitHandles)
    {
        jit->free(h);
    }
    ETISS_System *orig = (wrapSys)->orig;
    delete wrapSys;
    return orig;
}

} // namespace plugin

} // namespace etiss
