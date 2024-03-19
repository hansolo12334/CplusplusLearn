#include"hansolo_tcp.h"


int main()
{
    hansolo_tcp my_tcp{};
    std::cout << "测试  将select模型 集成到class\n";
    my_tcp.init_server_tcp(8000);
    for (;;){
        my_tcp.tcp_server_update_once();
    }


    return 0;
}
