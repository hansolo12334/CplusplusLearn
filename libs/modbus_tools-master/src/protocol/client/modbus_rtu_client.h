#pragma once
#include <iostream>
#include <vector>
#include "modbus_base_client.h"
#include "libmodbus/src/modbus-rtu.h"

class ModbusRtuClient : public ModbusBaseClient
{
public:
    ModbusRtuClient(const std::string &port, int baudRate, int byteSize, char parity, int stopBits);
    ModbusRtuClient() : ModbusRtuClient("/ttyUSB0", baudRate, byteSize, parity, stopBits){}; // 委托构造
    ~ModbusRtuClient() = default;

public:
    std::string port{"/ttyUSB0"}; // 端口
    int baudRate{9600};           // 波特率
    int byteSize{8};              // 数据位
    char parity{'N'};             // 奇偶校验
    int stopBits{1};              // 停止位
};