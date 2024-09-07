#include "modbus_base_client.h"
#include "log.h"

bool ModbusBaseClient::isConnected()
{
    return _isConnected;
}

ModbusBaseClient::~ModbusBaseClient()
{
    if (_ctx != nullptr)
    {
        modbus_close(_ctx);
        modbus_free(_ctx);
    }
}

std::vector<int> ModbusBaseClient::readCoilValues(int slaveId, int addr, int cnt)
{
    modbus_set_slave(_ctx, slaveId);
    uint8_t dest[cnt];
    memset(dest, 0, cnt * sizeof(uint8_t));
    int rc = modbus_read_bits(_ctx, addr, cnt, dest);
    if (rc == -1)
    {
        LOG_ERROR(fmt::format("readCoilValues failed, {}", modbus_strerror(errno)));
        return {};
    }
    std::vector<int> result;
    for (const auto &val : dest)
    {
        result.push_back(static_cast<int>(val));
    }
    return result;
}

bool ModbusBaseClient::writeCoilValue(int slaveId, int addr, int value)
{
    modbus_set_slave(_ctx, slaveId);
    int rc = modbus_write_bit(_ctx, addr, value);
    if (rc == -1)
    {
        LOG_ERROR(fmt::format("writeCoilValue failed, {}", modbus_strerror(errno)));
        return false;
    }
    else
    {
        return true;
    }
}

std::vector<int> ModbusBaseClient::readDiscreteInputValues(int slaveId, int addr, int cnt)
{
    modbus_set_slave(_ctx, slaveId);
    uint8_t dest[cnt];
    memset(dest, 0, cnt * sizeof(uint8_t));
    int rc = modbus_read_input_bits(_ctx, addr, cnt, dest);
    if (rc == -1)
    {
        LOG_ERROR(fmt::format("readDiscreteInputValues failed, {}", modbus_strerror(errno)));
        return {};
    }
    std::vector<int> result;
    for (const auto &val : dest)
    {
        result.push_back(static_cast<int>(val));
    }
    return result;
}

std::vector<int> ModbusBaseClient::readHoldRegisterValues(int slaveId, int addr, int cnt)
{
    modbus_set_slave(_ctx, slaveId);
    uint16_t dest[cnt];
    memset(dest, 0, cnt * sizeof(uint16_t));
    int rc = modbus_read_registers(_ctx, addr, cnt, dest);
    if (rc == -1)
    {
        LOG_ERROR(fmt::format("readHoldRegisterValues failed, {}", modbus_strerror(errno)));
        return {};
    }
    std::vector<int> result;
    for (const auto &val : dest)
    {
        result.push_back(static_cast<int>(val));
    }
    return result;
}

std::vector<int> ModbusBaseClient::readInputRegisterValues(int slaveId, int addr, int cnt)
{
    modbus_set_slave(_ctx, slaveId);
    uint16_t dest[cnt];
    memset(dest, 0, cnt * sizeof(uint16_t));
    int rc = modbus_read_input_registers(_ctx, addr, cnt, dest);
    if (rc == -1)
    {
        LOG_ERROR(fmt::format("readInputRegisterValues failed, {}", modbus_strerror(errno)));
        return {};
    }
    std::vector<int> result;
    for (const auto &val : dest)
    {
        result.push_back(static_cast<int>(val));
    }
    return result;
}

bool ModbusBaseClient::writeHoldRegisterValue(int slaveId, int addr, int value)
{
    modbus_set_slave(_ctx, slaveId);
    int rc = modbus_write_register(_ctx, addr, value);
    if (rc == -1)
    {
        LOG_ERROR(fmt::format("writeHoldRegisterValue failed, {}", modbus_strerror(errno)));
        return false;
    }
    else
    {
        return true;
    }
}

std::vector<int> ModbusBaseClient::readRangeCoilValues(int slaveId, int startAddr, int endAddr)
{
    modbus_set_slave(_ctx, slaveId);
    int cnt = endAddr - startAddr + 1;
    int num = cnt % 100 == 0 ? cnt / 100 : cnt / 100 + 1;
    std::vector<int> result;
    for (int i = 0; i < num; i++)
    {
        int addr = startAddr + i * 100;
        int cnt = 100;
        if (i == num - 1)
        {
            cnt = endAddr - addr + 1;
        }
        uint8_t dest[cnt];
        memset(dest, 0, cnt * sizeof(uint8_t));
        int rc = modbus_read_bits(_ctx, addr, cnt, dest);
        if (rc == -1)
        {
            LOG_ERROR(fmt::format("readCoilValues failed, {}", modbus_strerror(errno)));
            return {};
        }
        for (const auto &val : dest)
        {
            result.push_back(static_cast<int>(val));
        }
    }
    return result;
}
std::vector<int> ModbusBaseClient::readRangeDiscreteInputValues(int slaveId, int startAddr, int endAddr)
{
    modbus_set_slave(_ctx, slaveId);
    int cnt = endAddr - startAddr + 1;
    int num = cnt % 100 == 0 ? cnt / 100 : cnt / 100 + 1;
    std::vector<int> result;
    for (int i = 0; i < num; i++)
    {
        int addr = startAddr + i * 100;
        int cnt = 100;
        if (i == num - 1)
        {
            cnt = endAddr - addr + 1;
        }
        uint8_t dest[cnt];
        memset(dest, 0, cnt * sizeof(uint8_t));
        int rc = modbus_read_input_bits(_ctx, addr, cnt, dest);
        if (rc == -1)
        {
            LOG_ERROR(fmt::format("readDiscreteInputValues failed, {}", modbus_strerror(errno)));
            return {};
        }
        for (const auto &val : dest)
        {
            result.push_back(static_cast<int>(val));
        }
    }
    return result;
}

std::vector<int> ModbusBaseClient::readRangeHoldRegisterValues(int slaveId, int startAddr, int endAddr)
{
    modbus_set_slave(_ctx, slaveId);
    int cnt = endAddr - startAddr + 1;
    int num = cnt % 100 == 0 ? cnt / 100 : cnt / 100 + 1;
    std::vector<int> result;
    for (int i = 0; i < num; i++)
    {
        int addr = startAddr + i * 100;
        int cnt = 100;
        if (i == num - 1)
        {
            cnt = endAddr - addr + 1;
        }
        uint16_t dest[cnt];
        memset(dest, 0, cnt * sizeof(uint16_t));
        int rc = modbus_read_registers(_ctx, addr, cnt, dest);
        if (rc == -1)
        {
            LOG_ERROR(fmt::format("readDiscreteInputValues failed, {}", modbus_strerror(errno)));
            return {};
        }
        for (const auto &val : dest)
        {
            result.push_back(static_cast<int>(val));
        }
    }
    return result;
}

std::vector<int> ModbusBaseClient::readRangeInputRegisterValues(int slaveId, int startAddr, int endAddr)
{
    modbus_set_slave(_ctx, slaveId);
    int cnt = endAddr - startAddr + 1;
    int num = cnt % 100 == 0 ? cnt / 100 : cnt / 100 + 1;
    std::vector<int> result;
    for (int i = 0; i < num; i++)
    {
        int addr = startAddr + i * 100;
        int cnt = 100;
        if (i == num - 1)
        {
            cnt = endAddr - addr + 1;
        }
        uint16_t dest[cnt];
        memset(dest, 0, cnt * sizeof(uint16_t));
        int rc = modbus_read_input_registers(_ctx, addr, cnt, dest);
        if (rc == -1)
        {
            LOG_ERROR(fmt::format("readDiscreteInputValues failed, {}", modbus_strerror(errno)));
            return {};
        }
        for (const auto &val : dest)
        {
            result.push_back(static_cast<int>(val));
        }
    }
    return result;
}