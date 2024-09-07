#include <memory>
#include "protocol/client/modbus_tcp_client.h"
#include "gtest/gtest.h"

class ModbusTcpClientTest : public testing::Test
{
public:
    std::unique_ptr<ModbusTcpClient> client;

protected:
    virtual void SetUp()
    {
        try
        {
            client = std::make_unique<ModbusTcpClient>("10.10.111.54", 10502); // 创建Modbus客户端实例，监听端口5020
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
};

TEST_F(ModbusTcpClientTest, TestReadCoilValues)
{
    try
    {
        auto coilStatusList = client->readCoilValues(1, 0, 10);
        for (auto &status : coilStatusList)
        {
            std::cout << status << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST_F(ModbusTcpClientTest, TestReadHoldRegisterValues)
{
    try
    {
        auto holdValueList = client->readHoldRegisterValues(1, 156, 10);
        for (auto &value : holdValueList)
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST_F(ModbusTcpClientTest, TestReadInputRegisterValues)
{
    try
    {
        auto inputValueList = client->readInputRegisterValues(1, 156, 10);
        for (auto &value : inputValueList)
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST_F(ModbusTcpClientTest, TestReadRangeCoilValues)
{
    try
    {
        auto coilStatusList = client->readRangeCoilValues(1, 0, 1000);
        for (auto &status : coilStatusList)
        {
            std::cout << status << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST_F(ModbusTcpClientTest, TestReadRangeHoldRegisterValues)
{
    try
    {
        auto holdValueList = client->readRangeHoldRegisterValues(1, 100, 500);
        for (auto &value : holdValueList)
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST_F(ModbusTcpClientTest, TestReadRangeInputRegisterValues)
{
    try
    {
        auto inputValueList = client->readRangeInputRegisterValues(1, 100, 500);
        for (auto &value : inputValueList)
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST_F(ModbusTcpClientTest, TestWriteCoilValue)
{
    try
    {
        bool isSuccess = client->writeCoilValue(1, 50, 1);
        std::cout << isSuccess << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST_F(ModbusTcpClientTest, TestWriteHoldRegisterValue)
{
    try
    {
        bool isSuccess = client->writeHoldRegisterValue(1, 100, 100);
        std::cout << isSuccess << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}