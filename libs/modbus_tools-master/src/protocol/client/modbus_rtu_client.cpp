#include "modbus_rtu_client.h"
#include "log.h"

ModbusRtuClient::ModbusRtuClient(const std::string &port, int baudRate, int byteSize, char parity, int stopBits) : port(port), baudRate(baudRate), byteSize(byteSize), parity(parity), stopBits(stopBits)
{
    _ctx = modbus_new_rtu(port.c_str(), baudRate, parity, byteSize, stopBits); // 使用9600-N-8，1个停止位
    if (_ctx == nullptr)
    {
        _isConnected = false;
        LOG_ERROR("Unable to create the libmodbus context");
        return;
    }

    if (modbus_connect(_ctx) == -1)
    {
        _isConnected = false;
        LOG_ERROR(fmt::format("Connection failed: {0}", modbus_strerror(errno)));
        modbus_free(_ctx);
        _ctx = nullptr;
        return;
    }
    _isConnected = true;
    LOG_INFO("Connected to Modbus Serial server");
}