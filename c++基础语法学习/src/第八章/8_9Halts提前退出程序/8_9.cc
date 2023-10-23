#include<iostream>


//显式调用 st::exit()

void cleanup()
{
    std::cout << "clean up!\n";
}
int main()
{
    cleanup();

    //std::exit(0);

    cleanup();

    /*
    在上面的示例中，我们调用了函数 cleanup() 来处理清理任务。但是，记住在调用每次调用 exit（） 之前手动调用清理函数会增加程序员的负担。
    为了帮助实现这一点，C++提供了该 std::atexit() 函数，该函数允许您指定一个函数，该函数将在程序终止时通过 自动 std::exit() 调用。
    */

    std::atexit(cleanup);//执行完一次 cleanup
    std::exit(0);


    //std::abort and std::terminate



    return 0;
}
