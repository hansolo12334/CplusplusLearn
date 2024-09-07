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
#include "message_def.h"
#include "connect_rtu_view.h"
#include "protocol/client/modbus_tcp_client.h"
#include "single_modbus_client.h"
// #include "client.hpp"
#include "log.h"

ConnectRtuViewDialog::ConnectRtuViewDialog(const TRect &trect, const char *aTitle) : TDialog(trect, aTitle), TWindowInit(TDialog::initFrame)
{
    initDialog();
}

void ConnectRtuViewDialog::initDialog()
{
    portLabel = new TStaticText(TRect(10, 3, 20, 4), "设备端口:");
    portEditLine = new TInputLine(TRect(22, 3, 42, 4), 30);
    char *defaultPort = "/ttyUSB0";
    portEditLine->setData(defaultPort);
    this->insert(portLabel);
    this->insert(portEditLine);

    baudRateLabel = new TStaticText(TRect(10, 5, 20, 6), "波特率:");
    baudRateEditLine = new TInputLine(TRect(22, 5, 42, 6), 10);
    char *defaultBaudRate = "9600";
    baudRateEditLine->setData(defaultBaudRate);
    this->insert(baudRateLabel);
    this->insert(baudRateEditLine);

    byteSizeLabel = new TStaticText(TRect(10, 7, 20, 8), "数据位:");
    byteSizeEditLine = new TInputLine(TRect(22, 7, 42, 8), 10);
    char *defaultByteSize = "8";
    byteSizeEditLine->setData(defaultByteSize);
    this->insert(byteSizeLabel);
    this->insert(byteSizeEditLine);

    parityLabel = new TStaticText(TRect(10, 9, 20, 10), "校验位:");
    parityEditLine = new TInputLine(TRect(22, 9, 42, 10), 10);
    char *defaultParity = "N";
    parityEditLine->setData(defaultParity);
    this->insert(parityLabel);
    this->insert(parityEditLine);

    stopBitsLabel = new TStaticText(TRect(10, 11, 20, 12), "停止位:");
    stopBitsEditLine = new TInputLine(TRect(22, 11, 42, 12), 10);
    char *defaultStopBits = "1";
    stopBitsEditLine->setData(defaultStopBits);
    this->insert(stopBitsLabel);
    this->insert(stopBitsEditLine);

    connectButton = new TButton(TRect(25, 13, 35, 15), "连接", cmCommitConnectSerial, bfNormal);
    this->insert(connectButton);
}
void ConnectRtuViewDialog::connectServer()
{
    char portAddr[32];
    portEditLine->getData(portAddr);
    std::string port = std::string(portAddr);
    if (port.empty())
    {
        messageBox("请输入设备端口", mfError | mfOKButton);
        return;
    }

    char baudRateStr[32];
    baudRateEditLine->getData(baudRateStr);
    std::string baudRate = std::string(baudRateStr);
    if (baudRate.empty())
    {
        messageBox("请输入波特率", mfError | mfOKButton);
        return;
    }

    char byteSizeStr[32];
    byteSizeEditLine->getData(byteSizeStr);
    std::string byteSize = std::string(byteSizeStr);
    if (byteSize.empty())
    {
        messageBox("请输入数据位", mfError | mfOKButton);
        return;
    }

    char parityStr[32];
    parityEditLine->getData(parityStr);
    std::string parity = std::string(parityStr);
    if (parity.empty())
    {
        messageBox("请输入校验位", mfError | mfOKButton);
        return;
    }

    char stopBitsStr[32];
    stopBitsEditLine->getData(stopBitsStr);
    std::string stopBits = std::string(stopBitsStr);
    if (stopBits.empty())
    {
        messageBox("请输入停止位", mfError | mfOKButton);
        return;
    }

    try
    {
        int baudRateNum = std::stoi(baudRate);
        int byteSizeNum = std::stoi(byteSize);
        char parityNum = parity[0];
        int stopBitsNum = std::stoi(stopBits);
        RtuInfo rtuInfo(port, baudRateNum, byteSizeNum, parityNum, stopBitsNum);
        auto &client = SingleModbusRtuClient::getInstance(rtuInfo);
        if (client.isConnected())
        {
            currentConnectType = ConnectType::RTU;
            LOG_DEBUG(fmt::format("current connect type {}", static_cast<int>(currentConnectType)));
            messageBox("连接成功", mfInformation | mfOKButton);
        }
        else
        {
            messageBox("连接失败", mfError | mfOKButton);
        }
    }
    catch (...)
    {
        messageBox("请输入正确的参数", mfError | mfOKButton);
    }
}

TPalette &ConnectRtuViewDialog::getPalette() const
{
    static TPalette palette(cpBlueDialog, sizeof(cpBlueDialog) - 1);
    return palette;
}

void ConnectRtuViewDialog::handleEvent(TEvent &event)
{
    TDialog::handleEvent(event);
    if (event.what == evCommand)
    {
        switch (event.message.command)
        {
        case cmCommitConnectSerial:
        {
            connectServer();
            break;
        }
        case cmQuit:
        {
            clearEvent(event);
            break;
        }
        default:
            break;
        }
    }
}