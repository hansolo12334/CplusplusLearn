#include<iostream>
#include<string>
#include<vector>

#include <Python.h>
#include <numpy/arrayobject.h>//numpy的头文件


using namespace std;


int main()
{
    int nums{3};
    string strs="hello_python";
    Py_Initialize();

    if(!Py_IsInitialized()){
        cout << "Python 初始化失败\n";
        Py_Finalize();
        return -1;
    }
    import_array();//加载numpy相关的库

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/hansolo/CplusplusLearn/cplus_python/src/c++python混合编程/')");
    // PyRun_SimpleString("print(sys.path)");

    PyObject *pModule = nullptr;
    PyObject *pyFunc_mix = nullptr;

    pModule = PyImport_ImportModule("demo");

    if(!pModule){
        cout << "打开python文件失败\n";
        PyErr_Print();
        PyErr_Clear();
        Py_Finalize();
        return -1;
    }

    pyFunc_mix = PyObject_GetAttrString(pModule, "hello_world");

    if(pModule && PyCallable_Check(pyFunc_mix)){
        PyObject *pyParams = PyTuple_New(2);
        PyTuple_SetItem(pyParams, 0, Py_BuildValue("i", nums));
        PyTuple_SetItem(pyParams, 1, Py_BuildValue("s", strs.c_str()));

        PyObject *pyResult = PyObject_CallObject(pyFunc_mix, pyParams);


        if(pyResult==nullptr){
            cout << "调用失败\n";
            Py_Finalize();
            return -1;
        }

        if(!PyArray_Check(pyResult)){
            cout << "返回值不是numpy array\n";
            Py_Finalize();
            return -1;
        }

        PyArrayObject* ret_array=nullptr;

        PyArray_OutputConverter(pyResult, &ret_array);

        // npy_intp *shape = PyArray_SHAPE(ret_array);

        // cout << shape[0] << ' ' << shape[1] << endl;
        // auto datas =(npy_int *) PyArray_DATA(ret_array);
        // cout << ret_array->strides[0] << ' ' << ret_array->strides[1] << endl;
        cout <<"数组大小 "<< ret_array->dimensions[0] << 'X' << ret_array->dimensions[1] << endl;
        for (int i = 0; i < ret_array->dimensions[0]; i++)
        {
            for (int j = 0; j < ret_array->dimensions[1];j++){

                cout << *(int *)(ret_array->data + ret_array->strides[0] * i + ret_array->strides[1] * j) << ' ';
            }
            cout << endl;
        }
    }


    Py_Finalize();
    return 0;
}
