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
#include "connect_tcp_view.h"
#include "protocol/client/modbus_tcp_client.h"
#include "single_modbus_client.h"
// #include "client.hpp"
#include "log.h"

ConnectTcpViewDialog::ConnectTcpViewDialog(const TRect &trect, const char *aTitle) : TDialog(trect, aTitle), TWindowInit(TDialog::initFrame)
{
    initDialog();
}

void ConnectTcpViewDialog::initDialog()
{
    ipLabel = new TStaticText(TRect(15, 4, 20, 5), "IP:");
    ipEditLine = new TInputLine(TRect(22, 4, 42, 5), 30);
    char *defaultIp = "10.10.111.54";
    ipEditLine->setData(defaultIp);
    this->insert(ipLabel);
    this->insert(ipEditLine);

    portLabel = new TStaticText(TRect(15, 6, 20, 7), "Port:");
    portEditLine = new TInputLine(TRect(22, 6, 42, 7), 10);
    char *defaultPort = "10502";
    portEditLine->setData(defaultPort);
    this->insert(portLabel);
    this->insert(portEditLine);

    connectButton = new TButton(TRect(25, 8, 35, 10), "连接", cmCommitConnectTcp, bfNormal);
    this->insert(connectButton);
}

void ConnectTcpViewDialog::connectServer()
{
    char ipAddr[32];
    ipEditLine->getData(ipAddr);
    std::string ip = std::string(ipAddr);
    if (ip.empty())
    {
        messageBox("请输入IP地址", mfError | mfOKButton);
        return;
    }
    char portStr[32];
    portEditLine->getData(portStr);
    std::string port = std::string(portStr);
    if (port.empty())
    {
        messageBox("请输入端口号", mfError | mfOKButton);
        return;
    }

    try
    {
        int portNum = std::stoi(port);
        auto &client = SingleModbusTcpClient::getInstance(ip, portNum);
        if (client.isConnected())
        {
            currentConnectType = ConnectType::TCP;
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
        messageBox("请输入正确的参数!", mfError | mfOKButton);
    }
}

TPalette &ConnectTcpViewDialog::getPalette() const
{
    static TPalette palette(cpBlueDialog, sizeof(cpBlueDialog) - 1);
    return palette;
}

void ConnectTcpViewDialog::handleEvent(TEvent &event)
{
    TDialog::handleEvent(event);
    if (event.what == evCommand)
    {
        switch (event.message.command)
        {
        case cmCommitConnectTcp:
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