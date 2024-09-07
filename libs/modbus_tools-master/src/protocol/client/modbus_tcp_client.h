#pragma once
#include <iostream>
#include <vector>
#include "modbus_base_client.h"
#include "libmodbus/src/modbus-tcp.h"

class ModbusTcpClient : public ModbusBaseClient
{
public:
    ModbusTcpClient(const std::string ip, int port);
    ~ModbusTcpClient() = default;

public:
    std::string ip;
    int port;
};