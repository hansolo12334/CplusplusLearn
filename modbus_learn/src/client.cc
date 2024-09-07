#include "modbus/modbus.h"
#include <iostream>

#include<chrono>
#include<memory>
#include<thread>
// #pragma comment ( lib,"modbus.lib" )

#define SHUTDOWN_FUNCTION_CODE 0x66  // 自定义功能码用于通知下线

int main()
{
    modbus_t* ctx;
    uint16_t tab_reg[10];
    int rc;
    //创建Modbus TCP上下文
    ctx = modbus_new_tcp("127.0.0.1", 1502);
    // ctx = modbus_new_tcp("127.0.0.1", 3306);
    if (ctx == NULL)
    {
        std::cout << "Unable to create Modbus TCP context" << std::endl;
        return -1;
    }
    //连接到Modbus从设备
    rc = modbus_connect(ctx);
    if (rc == -1)
    {
        std::cout << "unable to connect to Modbus TCP slave" << std::endl;
        modbus_free(ctx);
        return -1;
    }

    //读取Modbus寄存器
    rc = modbus_read_registers(ctx, 0, 10, tab_reg);
    if (rc == -1)
    {
        std::cerr << "Unable to read Modbus registers" << std::endl;
        modbus_free(ctx);
        return -1;
    }
    //打印读取到的寄存器值
    for (int i = 0; i < rc; i++)
    {
        std::cout << "Register " << i << ": " << tab_reg[i] << std::endl;
    }


    // 通知服务器客户端将下线，使用自定义功能码
    // uint16_t shutdown_request = 0xFFFF; // 功能码 + 数据

    // rc=modbus_write_register(ctx,0, shutdown_request);

    // std::cout << rc << '\n';


    std::this_thread::sleep_for(std::chrono::seconds(1));

    modbus_close(ctx);

    modbus_free(ctx);

    return 0;
}
