#include "modbus_base_server.h"
#include <cstring>
#include "log.h"

ModbusBaseServer::~ModbusBaseServer()
{
    // 清理资源
    modbus_close(_ctx);
    modbus_free(_ctx);
    for (auto &mapping : _mappingList)
    {
        modbus_mapping_free(mapping);
    }
}

bool ModbusBaseServer::isAddressValid(int slaveId, int address)
{
    if (slaveId < 0 || slaveId > _slaveCount)
    {
        LOG_ERROR(fmt::format("从机号错误, 从机号: {}!", slaveId));
        return false;
    }
    if (address > (_numRegisters - 1))
    {
        LOG_ERROR(fmt::format("寄存器地址错误, 寄存器地址: {}!", address));
        return true;
    }
    return true;
}

void ModbusBaseServer::setCoilValue(int slaveId, int address, uint8_t value)
{
    if (!isAddressValid(slaveId, address))
        return;
    _mappingList[slaveId]->tab_bits[address] = value;
}

uint8_t ModbusBaseServer::getCoilValue(int slaveId, int address)
{
    if (!isAddressValid(slaveId, address))
        return 0;
    return _mappingList[slaveId]->tab_bits[address];
}

void ModbusBaseServer::setDiscreteInputValue(int slaveId, int address, uint8_t value)
{
    if (!isAddressValid(slaveId, address))
        return;
    _mappingList[slaveId]->tab_input_bits[address] = value;
}

uint8_t ModbusBaseServer::getDiscreteInputValue(int slaveId, int address)
{
    if (!isAddressValid(slaveId, address))
        return 0;
    return _mappingList[slaveId]->tab_input_bits[address];
}

void ModbusBaseServer::setInputRegisterValue(int slaveId, int address, uint16_t value)
{
    if (!isAddressValid(slaveId, address))
        return;
    _mappingList[slaveId]->tab_registers[address] = value;
}

uint16_t ModbusBaseServer::getInputRegisterValue(int slaveId, int address)
{
    if (!isAddressValid(slaveId, address))
        return 0;
    return _mappingList[slaveId]->tab_registers[address];
}

void ModbusBaseServer::setHoldRegisterValue(int slaveId, int address, uint16_t value)
{
    if (!isAddressValid(slaveId, address))
        return;
    _slavemutex.lock();
    _mappingList[slaveId]->tab_registers[address] = value;
    _slavemutex.unlock();
}

uint16_t ModbusBaseServer::getHoldRegisterValue(int slaveId, int address)
{
    if (!isAddressValid(slaveId, address))
        return 0;
    return _mappingList[slaveId]->tab_registers[address];
}