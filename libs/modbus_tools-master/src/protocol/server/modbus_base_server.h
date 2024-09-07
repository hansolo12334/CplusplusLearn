#pragma once
#include <vector>
#include <mutex>
#include "libmodbus/src/modbus.h"

class ModbusBaseServer
{
public:
    ModbusBaseServer() = default;
    ~ModbusBaseServer();

public:
    // 判断从机地址,寄存器地址是否合法
    bool isAddressValid(int slaveId, int address);
    // 线圈寄存器(功能码0x01,可读可写)
    void setCoilValue(int slaveId, int address, uint8_t value);
    uint8_t getCoilValue(int slaveId, int address);
    // 离散输入寄存器(功能码0x02,只读)
    void setDiscreteInputValue(int slaveId, int address, uint8_t value);
    uint8_t getDiscreteInputValue(int slaveId, int address);
    // 保持寄存器(功能码0x03,可读可写)
    void setHoldRegisterValue(int slaveId, int address, uint16_t value);
    uint16_t getHoldRegisterValue(int slaveId, int address);
    // 输入寄存器(功能码0x04,只读)
    void setInputRegisterValue(int slaveId, int address, uint16_t value);
    uint16_t getInputRegisterValue(int slaveId, int address);

    virtual void recieveMessages() = 0;
    virtual void start() = 0;

protected:
    modbus_t *_ctx;
    int _slaveCount;
    std::mutex _slavemutex;
    bool _initialized{false};
    /*Mapping*/
    std::vector<modbus_mapping_t *> _mappingList;
    int _numBits{65535};
    int _numInputBits{65535};
    int _numRegisters{65535};
    int _numInputRegisters{65535};
};