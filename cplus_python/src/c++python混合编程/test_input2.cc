#include<iostream>
#include<string>

#include <Python.h>
#include<numpy/arrayobject.h>

using namespace std;

int main()
{
    Py_Initialize();
    if(!Py_IsInitialized()){
        cout << "初始化失败\n";
        return -1;
    }
    import_array();

    PyObject *py_module, *py_func;

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/hansolo/CplusplusLearn/cplus_python/src/c++python混合编程/')");

    py_module = PyImport_ImportModule("demo");

    if(!py_module){
        cout << "加载py文件失败\n";
        Py_Finalize();
        return - 1;
    }
    py_func = PyObject_GetAttrString(py_module, "loop");

    if(!PyCallable_Check(py_func)){
        cout << "无法调用函数\n";
        Py_Finalize();
        return -1;
    }

    PyObject *py_value, *py_params, *py_result;

    py_params = PyTuple_New(2);


    for (int i = 0; i < 10; i++)
    {
        py_value = Py_BuildValue("s", "hello");
        PyTuple_SetItem(py_params,0, py_value);
        PyTuple_SetItem(py_params, 1, Py_BuildValue("i", i));
        py_result = PyObject_CallObject(py_func, py_params);
        if(!py_result){
        cout << "获取结果失败\n";
        Py_Finalize();
        return -1;
        }
    }

    Py_Finalize();
    return 0;
}
