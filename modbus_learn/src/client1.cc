#include "modbus/modbus.h"
#include <iostream>
// #pragma comment ( lib,"modbus.lib" )

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

    modbus_close(ctx);

    modbus_free(ctx);

    return 0;
}
