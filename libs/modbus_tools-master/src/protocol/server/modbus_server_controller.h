#include "modbus_base_server.h"
#include "util/protocol_config.h"
#include <map>
#include <memory>

// 业务处理类，根据功能码读取寄存器
class ModbusServerController
{
public:
    ModbusServerController(std::shared_ptr<ModbusBaseServer> modbusServer) : modbusServer(modbusServer){};

    RegisterType getRegisterType(int funcCode);

    int getRegisterValue(int slaveId, int funcCode, int address);
    void setRegisterValue(int slaveId, int funcCode, int address, int value);

    int getRegisterValueByBit(int slaveId, int funcCode, int address, int bit);
    void setRegisterValueByBit(int slaveId, int funcCode, int address, int bit, int value);

public:
    std::map<int, RegisterType> registerTypeMap = {
        {1, RegisterType::Coil},
        {2, RegisterType::DiscreteInput},
        {3, RegisterType::Hold},
        {4, RegisterType::Input},
        {6, RegisterType::Hold}};
    std::shared_ptr<ModbusBaseServer> modbusServer;
};