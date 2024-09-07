#include "protocol/server/modbus_tcp_server.h"
#include "gtest/gtest.h"

class ModbusTcpServerTest : public testing::Test
{
public:
    std::unique_ptr<ModbusTcpServer> server;

protected:
    virtual void SetUp()
    {
        try
        {
            server = std::make_unique<ModbusTcpServer>(5020, 10, true); // 创建Modbus服务器实例，监听端口5020，配置10台从机
            server->start();                                            // 启动服务器
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
};

TEST_F(ModbusTcpServerTest, TestSetRegisterValue)
{
    server->setHoldRegisterValue(1, 1, 100);
    ASSERT_EQ(100, server->getHoldRegisterValue(1, 1));

    server->setInputRegisterValue(1, 1, 200);
    ASSERT_EQ(200, server->getInputRegisterValue(1, 1));

    server->setCoilValue(1, 1, 1);
    ASSERT_TRUE(server->getCoilValue(1, 1));

    server->setDiscreteInputValue(1, 1, 1);
    ASSERT_TRUE(server->getDiscreteInputValue(1, 1));
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}