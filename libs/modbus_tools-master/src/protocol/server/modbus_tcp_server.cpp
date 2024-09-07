#include "modbus_tcp_server.h"
#include <cstring>
#include "log.h"

ModbusTcpServer::ModbusTcpServer(int port, int slaveCount, bool debug)
{
    this->_slaveCount = slaveCount;
    _ctx = modbus_new_tcp("10.10.111.173", port);
    // 设置从机地址
    modbus_set_slave(_ctx, 1);
    modbus_set_debug(_ctx, debug);
    if (_ctx == nullptr)
    {
        LOG_DEBUG("初始化ModbusServer错误!");
        throw -1;
    }
    if (_modbusSocket < 0)
    {
        _modbusSocket = modbus_tcp_listen(_ctx, 1);
    }
    // 设置从机0-slaveCount的地址映射
    for (int i = 0; i <= slaveCount; ++i)
    {
        /*设置线圈, 离散输入, 输入寄存器, 保持寄存器个数(数组元素个数))*/
        modbus_mapping_t *_mapping = modbus_mapping_new(_numBits, _numInputBits, _numInputRegisters, _numRegisters);
        _mappingList.push_back(_mapping);
        if (_mapping == nullptr)
        {
            LOG_ERROR("初始化ModbusMap失败!");
            modbus_free(_ctx);
            _initialized = false;
            return;
        }
    }
    LOG_INFO(fmt::format("ModbusTcpServer初始化成功, ip: {}, port: {}!", "127.0.0.1", port));
    _initialized = true;
}

void ModbusTcpServer::recieveMessages()
{
    // 初始化
    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
    fd_set reads, cpy_reads;
    FD_ZERO(&reads);
    FD_SET(_modbusSocket, &reads);
    int fdMax = _modbusSocket;
    while (true)
    {
        memset(query, 0, sizeof(query));
        cpy_reads = reads;
        int fdNum = select(fdMax + 1, &cpy_reads, 0, 0, 0);
        if (fdNum == -1)
            break;
        else if (fdNum == 0)
            continue;
        for (int i = 0; i < fdMax + 1; i++)
        {
            if (FD_ISSET(i, &cpy_reads))
            {
                if (i == _modbusSocket)
                {
                    int clntSock = modbus_tcp_accept(_ctx, &_modbusSocket);
                    if ((_modbusSocket == -1) || (clntSock == -1))
                    {
                        LOG_ERROR("accept error!");
                        std::cerr << modbus_strerror(errno) << std::endl;
                        continue;
                    }
                    FD_SET(clntSock, &reads);
                    if (fdMax < clntSock)
                        fdMax = clntSock;
                }
                else
                {
                    int ret = modbus_receive(_ctx, query);
                    if (ret == 0)
                    {
                        _errCount = 0;
                        continue;
                    }
                    else if (ret > 0)
                    {
                        _errCount = 0;
                        uint8_t slave = query[6]; // 获取收到问询的从机子号
                        if (slave <= static_cast<uint8_t>(_slaveCount))
                        {
                            modbus_set_slave(_ctx, slave);
                            modbus_reply(_ctx, query, sizeof(query), _mappingList[slave]);
                        }
                    }
                    else
                    {
                        modbus_set_error_recovery(_ctx, MODBUS_ERROR_RECOVERY_NONE);
                        modbus_set_error_recovery(_ctx, MODBUS_ERROR_RECOVERY_LINK);
                        modbus_close(_ctx);
                        FD_CLR(i, &reads);
                        LOG_ERROR("报文错误,服务端断开连接!");
                        close(i);
                        _errCount++;
                    }
                    if (_errCount > 5)
                    {
                        _initialized = false;
                        break;
                    }
                }
            }
        }
    }
    _initialized = false;
}
void ModbusTcpServer::start()
{
    LOG_INFO("ModbusTcpServer启动成功!");
    std::thread loop([this]()
                     {
        while (true)
        {
            if (_initialized)
            {
                recieveMessages();
            }
            else
            {
                _initialized = true;
            }
        } });
    loop.detach();
}