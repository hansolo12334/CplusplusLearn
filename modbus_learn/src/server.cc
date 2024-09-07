#include "modbus/modbus.h"
#include <iostream>

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


#define SHUTDOWN_FUNCTION_CODE 0x66  // 自定义功能码


int main()
{
    modbus_t* ctx;


    int rc;
    // 创建Modbus TCP服务器
    ctx = modbus_new_tcp("127.0.0.1", 1502);

    if(ctx==NULL){
        perror("Unable to create Modbus TCP context");
        return -1;
    }

    // 分配Modbus寄存器映射，包含0-32个保持寄存器
    modbus_mapping_t *mb_mapping = modbus_mapping_new(MODBUS_MAX_READ_BITS, MODBUS_MAX_WRITE_BITS, MODBUS_MAX_READ_REGISTERS, MODBUS_MAX_WRITE_REGISTERS);

    if(mb_mapping==NULL){
        std::cout << "Failed to allocate the mapping: " << modbus_strerror(errno) << '\n';

        return -1;
    }

     // 创建服务器端口
    int server_socket = modbus_tcp_listen(ctx, 10);
    if(server_socket==-1){
        std::cout << "Unable to listen for connections: " << modbus_strerror(errno) << '\n';
        modbus_mapping_free(mb_mapping);
        modbus_free(ctx);
        return -1;
    }

    while(1)
    {
        int client_socket = modbus_tcp_accept(ctx, &server_socket);
        if(client_socket==-1){
            std::cout << "Fail to accept connection :" << modbus_strerror(errno) << '\n';
            // modbus_free(ctx);
            // close(server_socket);
            break;
        }


        //设置字典数据
        for(int i = 0; i < 20;i++)
        {
            mb_mapping->tab_input_registers[i] = i;
            mb_mapping->tab_registers[i] = i;
        }

        while(1){
            uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];


            //接收client报文
            int rc = modbus_receive(ctx, query);

            std::cout << "rc: "<<rc << '\n';

            if (rc > 0)//处理报文
            {
                // std::cout << mb_mapping->tab_registers[0] << '\n';
                // if (mb_mapping->tab_registers[0] == 0xFFFF)
                // {
                //     std::cout << "客户端下线\n";
                //     break;
                // }

                 // 响应客户端请求，使用 mb_mapping 作为数据存储区
                 std::cout << "响应客户端请求\n";
                 modbus_reply(ctx, query, rc, mb_mapping);
            }
            else if(rc==-1){
                std::cout << "Connection closed or error: " << modbus_strerror(errno) << '\n';
                break;
            }
        }
        close(client_socket);
    }

    modbus_mapping_free(mb_mapping);
    modbus_free(ctx);
    close(server_socket);

    return 0;
}
