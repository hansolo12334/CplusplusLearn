#pragma once
#include <string>

enum class ProtocolType
{
    TCP,
    SERIAL,
    DLT645,
};

enum class RegisterType
{
    None = 0,
    Coil = 1,
    DiscreteInput = 2,
    Hold = 3,
    Input = 4,
};

class ModbusTcpConfig
{
public:
    int slaveCnt{1};
    std::string ip{"127.0.0.1"};
    int port{0};
};

class ModbusSerialConfig
{
public:
    int slaveCnt{0};
    std::string port{"/ttyUSB0"}; // 端口
    int baudRate{9600};           // 波特率
    int byteSize{8};              // 数据位
    char parity{'N'};             // 奇偶校验
    int stopBits{1};              // 停止位
};