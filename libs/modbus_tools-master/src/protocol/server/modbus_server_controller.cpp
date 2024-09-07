#include "modbus_server_controller.h"

RegisterType ModbusServerController::getRegisterType(int funcCode)
{
    if (registerTypeMap.find(funcCode) == registerTypeMap.end())
    {
        return RegisterType::None;
    }
    else
    {
        return registerTypeMap[funcCode];
    }
}

int ModbusServerController::getRegisterValue(int slaveId, int funcCode, int address)
{
    auto registerType = getRegisterType(funcCode);
    uint8_t value = 0;
    switch (registerType)
    {
    case RegisterType::Coil:
        value = modbusServer->getCoilValue(slaveId, address);
        break;
    case RegisterType::DiscreteInput:
        value = modbusServer->getDiscreteInputValue(slaveId, address);
        break;
    case RegisterType::Hold:
        value = modbusServer->getHoldRegisterValue(slaveId, address);
        break;
    case RegisterType::Input:
        value = modbusServer->getInputRegisterValue(slaveId, address);
        break;
    default:
        break;
    }
    return static_cast<int>(value);
}

void ModbusServerController::setRegisterValue(int slaveId, int funcCode, int address, int value)
{
    auto registerType = getRegisterType(funcCode);
    uint16_t val = static_cast<uint16_t>(value);
    switch (registerType)
    {
    case RegisterType::Coil:
        modbusServer->setCoilValue(slaveId, address, val);
        break;
    case RegisterType::DiscreteInput:
        modbusServer->setDiscreteInputValue(slaveId, address, val);
        break;
    case RegisterType::Hold:
        modbusServer->setHoldRegisterValue(slaveId, address, val);
        break;
    case RegisterType::Input:
        modbusServer->setInputRegisterValue(slaveId, address, val);
        break;
    default:
        break;
    }
}

int ModbusServerController::getRegisterValueByBit(int slaveId, int funcCode, int address, int bit)
{
    auto value = getRegisterValue(slaveId, funcCode, address);
    return value & (1 << bit);
}

void ModbusServerController::setRegisterValueByBit(int slaveId, int funcCode, int address, int bit, int value)
{
    auto oldValue = getRegisterValue(slaveId, funcCode, address);
    if (value)
    {
        oldValue |= (1 << bit);
    }
    else
    {
        oldValue &= ~(1 << bit);
    }
    setRegisterValue(slaveId, funcCode, address, oldValue);
}