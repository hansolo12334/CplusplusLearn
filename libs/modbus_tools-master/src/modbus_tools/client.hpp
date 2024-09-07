#include "protocol/client/modbus_tcp_client.h"
#include <iostream>
#include <memory>

class SingleClient
{
private:
    // 私有静态成员，用于存储唯一的ModbusTcpClient实例
    static std::unique_ptr<ModbusTcpClient> modbusClient;
    // 私有静态成员，用于存储SingleClient的唯一实例
    static std::unique_ptr<SingleClient> instance;

    // 私有构造函数，确保外部无法创建实例
    SingleClient(std::string ip, int port)
    {
        // 在这里初始化ModbusTcpClient，确保只创建一次
        if (!modbusClient)
        {
            // 注意：这里需要提供IP和端口，但你的原始代码中没有提供这些信息。
            // 你可能需要将它们作为参数传递给getInstance()方法，或者以其他方式提供。
            modbusClient = std::make_unique<ModbusTcpClient>(ip, port);
        }
    }

    // 私有析构函数，确保外部无法删除实例
    ~SingleClient() {}

    // 禁用拷贝构造函数和赋值运算符
    SingleClient(const SingleClient &) = delete;
    SingleClient &operator=(const SingleClient &) = delete;

public:
    // 获取SingleClient的唯一实例（单例）
    static SingleClient &getInstance(std::string ip, int port)
    {
        // 如果还没有创建实例，则创建一个
        if (!instance)
        {
            instance = std::make_unique<SingleClient>(ip, port);
        }
        // 返回对实例的引用
        return *instance;
    }

    // 获取ModbusTcpClient的实例
    ModbusTcpClient &getClient()
    {
        return *modbusClient;
    }
};

// 初始化静态成员
std::unique_ptr<ModbusTcpClient> SingleClient::modbusClient;
std::unique_ptr<SingleClient> SingleClient::instance;