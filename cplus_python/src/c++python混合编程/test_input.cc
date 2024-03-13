#include<iostream>
#include<string>
#include<vector>
#include<random>

#include <Python.h>
#include <numpy/arrayobject.h>//numpy的头文件


using namespace std;

int main()
{
    Py_Initialize();

    if(!Py_IsInitialized()){
        cout << "python 初始化失败\n";
        return -1;
    }
    import_array();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/hansolo/CplusplusLearn/cplus_python/src/c++python混合编程/')");

    PyObject *py_module, *py_func, *pyResult;

    py_module = PyImport_ImportModule("demo");

    if(!py_module){
        cout << "加载python文件失败\n";
        Py_Finalize();
        return -1;
    }
    py_func = PyObject_GetAttrString(py_module,"showIm");

    if(!PyCallable_Check(py_func)){
        cout << "函数无法调用！\n";
        Py_Finalize();
        return -1;
    }
    PyObject *py_params = nullptr;
    PyObject *pyValue1 = nullptr;


    double im_ctype_array[500][500];
    std::random_device rd{};
    std::mt19937 mt{rd()};
    std::uniform_int_distribution die6{0, 1};
    for (int i = 0; i < 500;i++){
        for (int j = 0; j < 500;j++){
            im_ctype_array[i][j] = die6(mt);
        }
    }

    npy_intp dims[] = {500, 500};      //二维
    pyValue1 = PyArray_SimpleNewFromData(2, dims, NPY_DOUBLE, im_ctype_array);
    py_params=PyTuple_New(1);

    PyTuple_SetItem(py_params, 0, pyValue1);

    pyResult = PyObject_CallObject(py_func, py_params);

    if(!pyResult){
        cout << "获取结果失败\n";
        Py_Finalize();
        return -1;
    }

    Py_Finalize();
    return 0;
}
