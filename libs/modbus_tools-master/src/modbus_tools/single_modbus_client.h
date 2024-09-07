#pragma once
#include "protocol/client/modbus_tcp_client.h"
#include "protocol/client/modbus_rtu_client.h"
#include "message_def.h"
#include <memory>

class SingleModbusTcpClient : public ModbusTcpClient
{
public:
    static ModbusTcpClient &getInstance(const std::string ip = "127.0.0.1", int port = 0)
    {
        std::lock_guard<std::mutex> lock(instanceMutex);

        // 如果IP和端口与当前的不一致，或者尚未实例化，则尝试创建新实例
        if (!instance || (currentIp != ip || currentPort != port))
        {
            // 尝试创建新实例，并在成功时更新状态
            try
            {
                instance = std::make_unique<ModbusTcpClient>(ip, port);
                currentIp = ip;
                currentPort = port;
            }
            catch (const std::exception &e)
            {
            }
        }

        // 返回当前实例的引用
        return *instance;
    }

    // 禁止外部复制和赋值
    SingleModbusTcpClient(const ModbusTcpClient &) = delete;
    SingleModbusTcpClient &operator=(const ModbusTcpClient &) = delete;

    static std::string getCurrentIp() noexcept
    {
        return currentIp;
    }

    static int getCurrentPort() noexcept
    {
        return currentPort;
    }

private:
    static std::unique_ptr<ModbusTcpClient> instance;
    static std::mutex instanceMutex;
    static std::string currentIp;
    static int currentPort;
};

struct RtuInfo
{
    std::string port{"/ttyUSB0"}; // 端口
    int baudRate{9600};           // 波特率
    int byteSize{8};              // 数据位
    char parity{'N'};             // 奇偶校验
    int stopBits{1};              // 停止位

    RtuInfo(std::string port = "/ttyUSB0", int baudRate = 9600, int byteSize = 8, char parity = 'N', int stopBits = 1)
        : port(port), baudRate(baudRate), byteSize(byteSize), parity(parity), stopBits(stopBits) {}

    friend bool operator==(const RtuInfo &a, const RtuInfo &b) noexcept
    {
        return a.port == b.port && a.baudRate == b.baudRate && a.byteSize == b.byteSize && a.parity == b.parity && a.stopBits == b.stopBits;
    }

    friend bool operator!=(const RtuInfo &a, const RtuInfo &b) noexcept
    {
        return !(a == b);
    }
};

class SingleModbusRtuClient : public ModbusRtuClient
{
public:
    static ModbusRtuClient &getInstance(const RtuInfo info = {"/ttyUSB0", 9600, 8, 'N', 1})
    {
        std::lock_guard<std::mutex> lock(instanceMutex);

        // 如果IP和端口与当前的不一致，或者尚未实例化，则尝试创建新实例
        if (!instance || (currentInfo != info))
        {
            try
            {
                instance = std::make_unique<ModbusRtuClient>(info.port, info.baudRate, info.byteSize, info.parity, info.stopBits);
                currentInfo = info;
            }
            catch (const std::exception &e)
            {
            }
        }
        return *instance;
    }

    // 禁止外部复制和赋值
    SingleModbusRtuClient(const ModbusRtuClient &) = delete;
    SingleModbusRtuClient &operator=(const ModbusRtuClient &) = delete;

    static RtuInfo &getCurrentInfo() noexcept
    {
        return currentInfo;
    }

    static void setCurrentInfo(const RtuInfo &info) noexcept
    {
        currentInfo = info;
    }

private:
    static std::unique_ptr<ModbusRtuClient> instance;
    static std::mutex instanceMutex;
    static RtuInfo currentInfo;
};

enum class ConnectType
{
    None,
    TCP,
    RTU
};

extern ConnectType currentConnectType;
extern RegisterType currentRegisterType;