/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "etiss/config.h"

#if ETISS_USE_PYTHON
#include <Python.h> // include before anyting else
#endif

#include "etiss/ETISS.h"

#if ETISS_USE_PYTHON
///////////////////////////////
// move to ETISS.h ? ETISSPython.h?

template <typename T>
PyObject *convert(const T &t)
{
    PyErr_SetString(PyExc_NotImplementedError, "failed to convert C++ object to PyObject");
    return nullptr;
}
template <>
PyObject *convert<std::string>(const std::string &s);
template <>
PyObject *convert<etiss::int32>(const etiss::int32 &s);

template <typename T>
T convert(PyObject *, bool &ok)
{
    ok = false;
    return T();
}

template <typename T1, typename T2, typename T3>
PyObject *convert(const std::tuple<T1, T2, T3> &a234)
{
    PyObject *list = PyList_New(0);
    PyObject *o = convert(std::get<0>(a234));
    if (o == 0)
    {
        Py_DecRef(list);
        return 0;
    }
    PyList_Append(list, o);
    Py_DecRef(o);
    o = convert(std::get<1>(a234));
    if (o == 0)
    {
        Py_DecRef(list);
        return 0;
    }
    PyList_Append(list, o);
    Py_DecRef(o);
    o = convert(std::get<2>(a234));
    if (o == 0)
    {
        Py_DecRef(list);
        return 0;
    }
    PyList_Append(list, o);
    Py_DecRef(o);
    return list;
}

template <typename T>
PyObject *convert(const std::set<T> &set)
{
    PyObject *list = PyList_New(0);
    for (auto iter = set.begin(); iter != set.end(); iter++)
    {
        PyObject *e = convert(*iter);
        if (e == 0)
        {
            Py_DecRef(list);
            return 0;
        }
        else
        {
            if (PyList_Append(list, convert(*iter)) != 0)
            {
                Py_DecRef(e);
                Py_DecRef(list);
                return 0;
            }
            Py_DecRef(e);
        }
    }
    return list;
}
template <typename T>
PyObject *convert(const std::list<T> &set)
{
    PyObject *list = PyList_New(0);
    for (auto iter = set.begin(); iter != set.end(); iter++)
    {
        PyObject *e = convert(*iter);
        if (e == 0)
        {
            Py_DecRef(list);
            return 0;
        }
        else
        {
            if (PyList_Append(list, convert(*iter)) != 0)
            {
                Py_DecRef(e);
                Py_DecRef(list);
                return 0;
            }
            Py_DecRef(e);
        }
    }
    return list;
}
template <typename K, typename V>
PyObject *convert(const std::map<K, V> &set)
{
    PyObject *dict = PyDict_New();
    for (auto iter = set.begin(); iter != set.end(); iter++)
    {
        PyObject *k = convert(iter->first);
        if (k == 0)
        {
            Py_DecRef(dict);
            return 0;
        }
        else
        {
            PyObject *v = convert(iter->second);
            if (v == 0)
            {
                Py_DecRef(k);
                Py_DecRef(dict);
                return 0;
            }
            else
            {
                if (PyDict_SetItem(dict, k, v) != 0)
                {
                    Py_DecRef(k);
                    Py_DecRef(v);
                    Py_DecRef(dict);
                    return 0;
                }
                Py_DecRef(k);
                Py_DecRef(v);
            }
        }
    }
    return dict;
}

///////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// PYTHON

///////////////////////////////////////////////////////////////
// conversion

template <>
PyObject *convert<std::string>(const std::string &s)
{
    return PyString_FromString(s.c_str());
}
template <>
PyObject *convert<etiss::int32>(const etiss::int32 &s)
{
    return PyInt_FromSsize_t(s);
}

template <>
std::string convert<std::string>(PyObject *o, bool &ok)
{
    char *str = PyString_AsString(o);
    if (str != nullptr)
    {
        return std::string(str);
    }
    else
    {
        ok = false;
        return "";
    }
}

// /conversion
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// helper functions
template <std::set<std::string> (*list)()>
static PyObject *pyetiss_listX(PyObject *self, PyObject *args)
{
    return convert(list());
}
template <std::list<std::string> (*list)()>
static PyObject *pyetiss_listX(PyObject *self, PyObject *args)
{
    return convert(list());
}

static PyObject *pyetiss_loadLibrary(PyObject *self, PyObject *args)
{
    const char *name;
    const char *path;

    if (!PyArg_ParseTuple(args, "ss", &name, &path))
    {
        Py_IncRef(Py_False);
        return Py_False;
    }

    if (etiss::loadLibrary(std::string(name), std::string(path)))
    {
        Py_IncRef(Py_True);
        return Py_True;
    }
    else
    {
        Py_IncRef(Py_False);
        return Py_False;
    }
}

static PyObject *pyetiss_cfg_get(PyObject *self, PyObject *args)
{
    const char *name;
    const char *def;

    if (!PyArg_ParseTuple(args, "ss", &name, &def))
        return nullptr;
    return convert(etiss::cfg().get<std::string>(std::string(name), std::string(def)));
}
static PyObject *pyetiss_cfg_set(PyObject *self, PyObject *args)
{
    const char *name;
    const char *def;

    if (!PyArg_ParseTuple(args, "ss", &name, &def))
        return nullptr;
    return convert(etiss::cfg().get<std::string>(std::string(name), std::string(def)));
}
static PyObject *pyetiss_cfg_all(PyObject *self, PyObject *args)
{
    return convert(etiss::cfg().config());
}
static PyObject *pyetiss_cfg_help(PyObject *self, PyObject *args)
{
    return convert(etiss::cfg().getAnnounced());
}

static PyObject *pyetiss_returnCodes(PyObject *self, PyObject *args)
{
    std::map<etiss::int32, const char *> m = etiss::RETURNCODE::getErrorMessages();
    std::map<etiss::int32, std::string> ret;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        ret[iter->first] = std::string(etiss::RETURNCODE::getErrorNames()[iter->first]) + ": " + iter->second;
    }
    return convert(ret);
}

// /helper functions
///////////////////////////////////////////////////////////////

// function register table
static PyMethodDef ETISSMethods[] = {

    { "listCPUArchs", pyetiss_listX<etiss::listCPUArchs>, METH_VARARGS, "List available cpu architectures." },
    { "listJITs", pyetiss_listX<etiss::listJITs>, METH_VARARGS, "List compilers." },
    { "listPlugins", pyetiss_listX<etiss::listPlugins>, METH_VARARGS, "List plugins." },
    { "listCPUs", pyetiss_listX<etiss::CPUCore::list>, METH_VARARGS, "List plugins." },
    { "listLibraries", pyetiss_listX<etiss::listLibraries>, METH_VARARGS, "List loaded libraries." },
    { "loadLibrary", pyetiss_loadLibrary, METH_VARARGS, "Try to open a shared library." },
    { "cfgGet", pyetiss_cfg_get, METH_VARARGS, "Get the string value of an option" },
    { "cfgSet", pyetiss_cfg_set, METH_VARARGS, "Set the string value of an option" },
    { "cfg", pyetiss_cfg_all, METH_VARARGS, "Get all options in a list" },
    { "cfgHelp", pyetiss_cfg_help, METH_VARARGS, "Get all announced option info in a dictionary" },
    { "RETURNCODES", pyetiss_returnCodes, METH_VARARGS, "Get global return codes" },
    { NULL, NULL, 0, NULL } /* Sentinel */
};

// /function register table
////////////////////////////////////////////////////////////////

// initialization

extern "C"
{
    /**
        python etiss init function. allows to use etiss as a module in python
    */
    void initETISS()
    {
        static bool done = false;
        if (done)
            return;
        done = true;
        Py_InitModule3("etiss", ETISSMethods, "ETISS python bindings");
    }
}

// /PYTHON
///////////////////////////////////////////////////////////////////////////////////////

PyThreadState *etiss_main_pyThreadState = 0;

namespace etiss
{
namespace py
{

bool supported()
{
    return true;
}

void run(std::function<void(void)> func)
{
    PyGILState_STATE gstate = PyGILState_Ensure();
    func();
    PyGILState_Release(gstate);
}

void runEXT(std::function<void(void)> func)
{
    Py_BEGIN_ALLOW_THREADS func();
    Py_END_ALLOW_THREADS
}

void runString(const char *s)
{
    run([&s]() { PyRun_SimpleString(s); });
}

void console()
{
    initETISS();
    runString("print('ETISS functions are provided the the module \\'etiss\\'.')");
    runString("import code;\ncode.interact(\"ETISS Python Console\")");
}

void init()
{

    if (etiss::cfg().get<bool>("pyinitialize", true))
    {
        Py_Initialize();
        if (etiss::cfg().get<bool>("pyinittheads", true))
        {
            if (PyEval_ThreadsInitialized() == 0)
            {
                PyEval_InitThreads(); // init gil
                PyEval_ReleaseLock(); // release gil
                etiss::log(etiss::VERBOSE, "PyEval_InitThreads() called.");
            }
        }
        etiss::log(etiss::VERBOSE, "Py_Initialize() called.");
    }

    run([]() {
        PyEval_AcquireLock(); // lock gil
        if (etiss::verbosity() >= etiss::INFO)
            PyRun_SimpleString("print('ETISS: INFO: ETISS has been build with python support.')\n");
        // Py_InitModule3("etiss", ETISSMethods,"ETISS python bindings");
        PyEval_ReleaseLock(); // release gil
    });
}

void shutdown()
{
    if (etiss::cfg().get<bool>("pyfinalize", true))
    {
        Py_Finalize();
        etiss::log(etiss::VERBOSE, "Py_Finalize() called");
    }
}

std::string evalForString(const char *stmt, bool *ok = nullptr)
{
    if (ok != 0)
        *ok = false;
    PyObject *result = 0;
    run([stmt, &result]() {
        PyObject *main = PyImport_AddModule("__main__");
        if (main == 0)
        {
            return;
        }
        PyObject *globalDictionary = PyModule_GetDict(main);
        if (globalDictionary == 0)
        {
            return;
        }
        PyObject *localDictionary = PyDict_New();
        if (localDictionary == 0)
        {
            return;
        }
        result = PyRun_String(stmt, Py_file_input, globalDictionary, localDictionary);
    });
    if (result == 0)
        return "";
    bool lok = false;
    std::string ret = convert<std::string>(result, ok ? *ok : lok);
    Py_DecRef(result);
    return ret;
}

} // namespace py
} // namespace etiss

#else
// ETISS_USE_PYTHON == 0

namespace etiss
{
namespace py
{

void init() {}

void shutdown() {}

void console() {}

bool supported()
{
    return false;
}

void runString(std::string s) {}

void run(std::function<void(void)> func) {}

std::string evalForString(const char *stmt, bool *ok = nullptr)
{
    if (ok)
        *ok = false;
    return "";
}

} // namespace py
} // namespace etiss

#endif
