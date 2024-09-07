#pragma once
#include <vector>
#include <string>
#include "libmodbus/src/modbus.h"

class ModbusBaseClient
{
public:
    ModbusBaseClient() = default;
    ~ModbusBaseClient();

    bool isConnected();
    // 线圈寄存器(功能码0x01,可读可写)
    std::vector<int> readCoilValues(int slaveId, int addr, int cnt);
    bool writeCoilValue(int slaveId, int addr, int value);
    // 离散输入寄存器(功能码0x02,只读)
    std::vector<int> readDiscreteInputValues(int slaveId, int addr, int cnt);
    // 保持寄存器(功能码0x03,可读可写)
    std::vector<int> readHoldRegisterValues(int slaveId, int addr, int cnt);
    bool writeHoldRegisterValue(int slaveId, int addr, int value);
    // 输入寄存器(功能码0x04,只读)
    std::vector<int> readInputRegisterValues(int slaveId, int addr, int cnt);

    // 根据地址范围读取寄存器,起始地址-结束地址
    std::vector<int> readRangeCoilValues(int slaveId, int startAddr, int endAddr);
    std::vector<int> readRangeDiscreteInputValues(int slaveId, int startAddr, int endAddr);
    std::vector<int> readRangeHoldRegisterValues(int slaveId, int startAddr, int endAddr);
    std::vector<int> readRangeInputRegisterValues(int slaveId, int startAddr, int endAddr);

protected:
    modbus_t *_ctx{nullptr};
    bool _isConnected{false};
};