#define Uses_TApplication
#define Uses_TRect
#define Uses_TScrollBar
#define Uses_TInputLine
#define Uses_TDialog
#define Uses_TListBox
#define Uses_TEvent
#define Uses_TScrollBar
#define Uses_TStaticText
#define Uses_TKeys
#define Uses_TWindow
#define Uses_TView
#define Uses_MsgBox
#define Uses_TRect
#define Uses_TButton
#define Uses_TStatusLine
#include "message_def.h"
#include "protocol/client/modbus_tcp_client.h"
#include "single_modbus_client.h"
#include "modbus_view.h"
#include <variant>
#include "log.h"

ModbusViewDialog::ModbusViewDialog(const TRect &trect, const char *aTitle) : TDialog(trect, aTitle), TWindowInit(TDialog::initFrame)
{
    initReadDataModule();
    if (currentRegisterType == RegisterType::Coil || currentRegisterType == RegisterType::Hold)
    {
        initWriteDataModule();
    }
}

void ModbusViewDialog::initReadDataModule()
{
    int midX = size.x / 2;
    int midY = size.y / 2;

    readModule.title = new TStaticText(TRect(midX - 47, midY - 8, midX - 37, midY - 7), "读取寄存器");
    this->insert(readModule.title);

    readModule.rtuAddrText = new TStaticText(TRect(midX - 60, midY - 6, midX - 50, midY - 5), "从机地址:");
    readModule.rtuAddrEditLine = new TInputLine(TRect(midX - 48, midY - 6, midX - 28, midY - 5), 30);
    char *defaultSlave = "1";
    readModule.rtuAddrEditLine->setData(defaultSlave);
    this->insert(readModule.rtuAddrText);
    this->insert(readModule.rtuAddrEditLine);

    readModule.startAddressText = new TStaticText(TRect(midX - 60, midY - 4, midX - 50, midY - 3), "起始地址:");
    readModule.startAddressEditLine = new TInputLine(TRect(midX - 48, midY - 4, midX - 28, midY - 3), 10);
    char *defaultStartAddress = "1";
    readModule.startAddressEditLine->setData(defaultStartAddress);
    this->insert(readModule.startAddressText);
    this->insert(readModule.startAddressEditLine);

    readModule.endAddressText = new TStaticText(TRect(midX - 60, midY - 2, midX - 50, midY - 1), "结束地址:");
    readModule.endAddressEditLine = new TInputLine(TRect(midX - 48, midY - 2, midX - 28, midY - 1), 10);
    char *defaultEndAddress = "100";
    readModule.endAddressEditLine->setData(defaultEndAddress);
    this->insert(readModule.endAddressText);
    this->insert(readModule.endAddressEditLine);

    readModule.searchButton = new TButton(TRect(midX - 47, midY, midX - 37, midY + 2), "查询", cmCommitSearch, bfNormal);
    this->insert(readModule.searchButton);
}

void ModbusViewDialog::initWriteDataModule()
{
    int midX = size.x / 2;
    int midY = size.y / 2;

    writeModule.title = new TStaticText(TRect(midX + 30, midY - 8, midX + 40, midY - 7), "写入寄存器");
    this->insert(writeModule.title);

    writeModule.rtuAddrText = new TStaticText(TRect(midX + 18, midY - 6, midX + 28, midY - 5), "从机地址:");
    writeModule.rtuAddrEditLine = new TInputLine(TRect(midX + 30, midY - 6, midX + 50, midY - 5), 30);
    char *defaultSlave = "1";
    writeModule.rtuAddrEditLine->setData(defaultSlave);
    this->insert(writeModule.rtuAddrText);
    this->insert(writeModule.rtuAddrEditLine);

    writeModule.addressText = new TStaticText(TRect(midX + 18, midY - 4, midX + 28, midY - 3), "地址:");
    writeModule.addressEditLine = new TInputLine(TRect(midX + 30, midY - 4, midX + 50, midY - 3), 10);
    char *defaultStartAddress = "1";
    writeModule.addressEditLine->setData(defaultStartAddress);
    this->insert(writeModule.addressText);
    this->insert(writeModule.addressEditLine);

    writeModule.valueText = new TStaticText(TRect(midX + 18, midY - 2, midX + 28, midY - 1), "值:");
    writeModule.valueEditLine = new TInputLine(TRect(midX + 30, midY - 2, midX + 50, midY - 1), 10);
    char *defaultEndAddress = "100";
    writeModule.valueEditLine->setData(defaultEndAddress);
    this->insert(writeModule.valueText);
    this->insert(writeModule.valueEditLine);

    writeModule.writeButton = new TButton(TRect(midX + 30, midY, midX + 40, midY + 2), "写入", cmCommitWrite, bfNormal);
    this->insert(writeModule.writeButton);
}

// void ModbusViewDialog::draw()
// {
//     // 中间画一个分割线
//     TDrawBuffer b;
//     b.moveChar(50, (char)179, getColor(1), 1);
//     writeLine(60, 10, 20, 1, b);
//     TView::draw();
// }

TPalette &ModbusViewDialog::getPalette() const
{
    static TPalette palette(cpBlueDialog, sizeof(cpBlueDialog) - 1);
    return palette;
}

void ModbusViewDialog::searchData()
{
    char slave[10];
    readModule.rtuAddrEditLine->getData(slave);
    std::string slaveId = std::string(slave);
    if (slaveId.empty())
    {
        messageBox("请输入从机地址", mfError | mfOKButton);
        return;
    }

    char start[10];
    readModule.startAddressEditLine->getData(start);
    std::string startAddr = std::string(start);
    if (startAddr.empty())
    {
        messageBox("请输入起始寄存器地址", mfError | mfOKButton);
        return;
    }

    char end[10];
    readModule.endAddressEditLine->getData(end);
    std::string endAddr = std::string(end);
    if (startAddr.empty())
    {
        messageBox("请输入结束寄存器地址", mfError | mfOKButton);
        return;
    }

    try
    {
        int slaveNum = std::stoi(slaveId);
        int startAddrNum = std::stoi(startAddr);
        int endAddrNum = std::stoi(endAddr);

        auto loadDialog = [&](auto &client)
        {
            switch (currentRegisterType)
            {
            case RegisterType::Coil:
            {
                auto registerDataList = client.readRangeCoilValues(slaveNum, startAddrNum, endAddrNum);
                loadDataViewDialog(startAddrNum, registerDataList);
                break;
            }
            case RegisterType::DiscreteInput:
            {
                auto registerDataList = client.readRangeDiscreteInputValues(slaveNum, startAddrNum, endAddrNum);
                loadDataViewDialog(startAddrNum, registerDataList);
                break;
            }
            case RegisterType::Hold:
            {
                auto registerDataList = client.readRangeHoldRegisterValues(slaveNum, startAddrNum, endAddrNum);
                loadDataViewDialog(startAddrNum, registerDataList);
                break;
            }
            case RegisterType::Input:
            {
                auto registerDataList = client.readRangeInputRegisterValues(slaveNum, startAddrNum, endAddrNum);
                loadDataViewDialog(startAddrNum, registerDataList);
                break;
            }
            default:
                break;
            }
        };

        LOG_DEBUG(fmt::format("current connect type {}", static_cast<int>(currentConnectType)));
        if (currentConnectType == ConnectType::TCP)
        {
            std::string ip = SingleModbusTcpClient::getCurrentIp();
            int port = SingleModbusTcpClient::getCurrentPort();
            auto &client = SingleModbusTcpClient::getInstance(ip, port);
            LOG_DEBUG(fmt::format("current ip {}, current port {}", ip, port));
            LOG_DEBUG(fmt::format("current register type {}", static_cast<int>(currentRegisterType)));

            if (!client.isConnected())
            {
                messageBox("未连接Modbus TCP服务器!", mfError | mfOKButton);
                return;
            }
            loadDialog(client);
        }
        else if (currentConnectType == ConnectType::RTU)
        {
            auto currentInfo = SingleModbusRtuClient::getCurrentInfo();
            LOG_DEBUG(fmt::format("current port {},current baduRate {}, current byteSize {}, current parity {},current stopBits {}",
                                  currentInfo.port, currentInfo.baudRate, currentInfo.byteSize, currentInfo.parity, currentInfo.stopBits));
            auto &client = SingleModbusRtuClient::getInstance(currentInfo);
            if (!client.isConnected())
            {
                messageBox("未连接Modbus RTU服务器!", mfError | mfOKButton);
                return;
            }
            loadDialog(client);
        }
        else
        {
            messageBox("未连接任何服务器!", mfError | mfOKButton);
        }
    }
    catch (std::invalid_argument &e)
    {
        messageBox("查询失败", mfError | mfOKButton);
    }
}

void ModbusViewDialog::writeData()
{
    char slave[10];
    writeModule.rtuAddrEditLine->getData(slave);
    std::string slaveId = std::string(slave);
    if (slaveId.empty())
    {
        messageBox("请输入从机地址", mfError | mfOKButton);
        return;
    }

    char address[10];
    writeModule.addressEditLine->getData(address);
    std::string addr = std::string(address);
    if (addr.empty())
    {
        messageBox("请输入地址", mfError | mfOKButton);
        return;
    }

    char value[10];
    writeModule.valueEditLine->getData(value);
    std::string valueStr = std::string(value);
    if (valueStr.empty())
    {
        messageBox("请输入值", mfError | mfOKButton);
        return;
    }

    try
    {
        int slaveNum = std::stoi(slaveId);
        int addrNum = std::stoi(addr);
        int valueNum = std::stoi(valueStr);

        auto loadDialog = [&](auto &client)
        {
            switch (currentRegisterType)
            {
            case RegisterType::Coil:
            {
                auto registerDataList = client.writeCoilValue(slaveNum, addrNum, valueNum);
                messageBox("写入数据成功", mfInformation | mfOKButton);
                break;
            }
            case RegisterType::Hold:
            {
                auto registerDataList = client.writeHoldRegisterValue(slaveNum, addrNum, valueNum);
                messageBox("写入数据成功", mfInformation | mfOKButton);
                break;
            }
            default:
                break;
            }
        };

        LOG_DEBUG(fmt::format("current connect type {}", static_cast<int>(currentConnectType)));
        if (currentConnectType == ConnectType::TCP)
        {
            std::string ip = SingleModbusTcpClient::getCurrentIp();
            int port = SingleModbusTcpClient::getCurrentPort();
            auto &client = SingleModbusTcpClient::getInstance(ip, port);
            LOG_DEBUG(fmt::format("current ip {}, current port {}", ip, port));
            LOG_DEBUG(fmt::format("current register type {}", static_cast<int>(currentRegisterType)));

            if (!client.isConnected())
            {
                messageBox("未连接Modbus TCP服务器!", mfError | mfOKButton);
                return;
            }
            loadDialog(client);
        }
        else if (currentConnectType == ConnectType::RTU)
        {
            auto currentInfo = SingleModbusRtuClient::getCurrentInfo();
            LOG_DEBUG(fmt::format("current port {},current baduRate {}, current byteSize {}, current parity {},current stopBits {}",
                                  currentInfo.port, currentInfo.baudRate, currentInfo.byteSize, currentInfo.parity, currentInfo.stopBits));
            auto &client = SingleModbusRtuClient::getInstance(currentInfo);
            if (!client.isConnected())
            {
                messageBox("未连接Modbus RTU服务器!", mfError | mfOKButton);
                return;
            }
            loadDialog(client);
        }
        else
        {
            messageBox("未连接任何服务器!", mfError | mfOKButton);
        }
    }
    catch (std::invalid_argument &e)
    {
        messageBox("写入数据失败", mfError | mfOKButton);
    }
}

void ModbusViewDialog::handleEvent(TEvent &event)
{
    if (event.what == evCommand)
    {
        switch (event.message.command)
        {
        case cmCommitSearch:
        {
            searchData();
            break;
        }
        case cmCommitWrite:
        {
            writeData();
            break;
        }
        default:
            break;
        }
    }
    else if (event.what == evKeyDown)
    {
        switch (event.keyDown.keyCode)
        {
        case kbEsc:
        {
            break;
        }
        default:
            break;
        }
    }
    TDialog::handleEvent(event);
}

void ModbusViewDialog::loadDataViewDialog(int startAddr, std::vector<int> registerDataList)
{
    TRect r = father->getExtent(); // 获取父窗口的大小
    r.grow(-1, -1);
    std::string title = fmt::format("查看数据");
    dataViewDialog = new DataViewDialog(r, title.c_str());
    dataViewDialog->initRegisterListData(startAddr, registerDataList);
    dataViewDialog->initListViewDialog();
    this->insert(dataViewDialog);
    dataViewDialog->show();
    dataViewDialog->select();
}