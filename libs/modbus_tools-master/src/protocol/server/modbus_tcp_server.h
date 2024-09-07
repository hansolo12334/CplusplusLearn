#pragma once
#include <iostream>
#include <vector>
#include <mutex>
#include "libmodbus/src/modbus-tcp.h"
#include "modbus_base_server.h"

class ModbusTcpServer : public ModbusBaseServer
{
public:
    ModbusTcpServer(int port, int slaveCount, bool debug);
    ~ModbusTcpServer() = default;

    void recieveMessages() override;
    void start() override;

private:
    int _errCount{0};
    int _modbusSocket{-1};
};
