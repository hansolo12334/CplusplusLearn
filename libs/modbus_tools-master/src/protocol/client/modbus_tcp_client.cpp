#include "modbus_tcp_client.h"
#include "log.h"

ModbusTcpClient::ModbusTcpClient(const std::string ip, int port) : ip(ip), port(port)
{
    _ctx = modbus_new_tcp(ip.c_str(), port);
    if (_ctx == nullptr)
    {
        _isConnected = false;
        LOG_ERROR("Unable to create the libmodbus context");
        return;
    }

    if (modbus_connect(_ctx) == -1)
    {
        LOG_ERROR(fmt::format("Connection failed, {}", modbus_strerror(errno)));
        modbus_free(_ctx);
        _ctx = nullptr;
        _isConnected = false;
        return;
    }
    _isConnected = true;
    LOG_INFO("Connected to Modbus Tcp server");
}