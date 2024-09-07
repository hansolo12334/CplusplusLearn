#define Uses_TApplication
#define Uses_TBackground
#define Uses_TButton
#define Uses_TInputLine
#define Uses_TKeys
#define Uses_TDeskTop
#define Uses_TDialog
#define Uses_TListBox
#define Uses_TMenu
#define Uses_TMenuBar
#define Uses_TMenuItem
#define Uses_TRect
#define Uses_TScrollBar
#define Uses_TStaticText
#define Uses_TStatusDef
#define Uses_TStatusItem
#define Uses_TStatusLine

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <tvision/tv.h>
#include "protocol/client/modbus_tcp_client.h"
#include "single_modbus_client.h"
#include "log.h"
#include "message_def.h"
#include "connect_tcp_view.h"
#include "connect_rtu_view.h"
#include "modbus_view.h"

// 初始化静态成员
std::unique_ptr<ModbusTcpClient> SingleModbusTcpClient::instance = nullptr;
std::mutex SingleModbusTcpClient::instanceMutex;
std::string SingleModbusTcpClient::currentIp = "127.0.0.1";
int SingleModbusTcpClient::currentPort = 502;

std::unique_ptr<ModbusRtuClient> SingleModbusRtuClient::instance = nullptr;
std::mutex SingleModbusRtuClient::instanceMutex;
RtuInfo SingleModbusRtuClient::currentInfo;

ConnectType currentConnectType = ConnectType::None;
RegisterType currentRegisterType = RegisterType::None;

class TApp : public TApplication
{
public:
    TApp();

    static TMenuBar *initMenuBar(TRect r);
    void handleEvent(TEvent &event);
    void idle();

public:
    TStaticText *connectStatusLine;
    ConnectTcpViewDialog *connectTcpViewDialog;
    ConnectRtuViewDialog *connectRtuViewDialog;
    ModbusViewDialog *coilRegisterDialog, *discreteInputRegisterDialog, *holdRegisterDialog, *inputRegisterDialog;
};

TApp::TApp()
    : TProgInit(TApplication::initStatusLine, TApp::initMenuBar, TApplication::initDeskTop)
{
    TRect r = getExtent();
    r.a.x = r.b.x - 13;
    r.a.y = r.b.y - 1;

    // connectStatusLine = new TStaticText(TRect(25, 5, 35, 6), "未连接");
    // this->insert(connectStatusLine);

    // Display about box
    TEvent event;
    event.what = evCommand;
    event.message.command = cmConnectTcpServer;
    putEvent(event);
}

TMenuBar *TApp::initMenuBar(TRect r)
{
    r.b.y = r.a.y + 1;
    TMenuBar *menuBar = new TMenuBar(
        r,
        new TMenu(
            *new TMenuItem("~串口~连接(F1)",
                           Commands::cmConnectSerailServer,
                           kbF1,
                           hcNoContext,
                           0) +
            *new TMenuItem("~TCP~连接(F2)",
                           Commands::cmConnectTcpServer,
                           kbF2,
                           hcNoContext,
                           0) +
            *new TMenuItem("~线圈(01功能码)~寄存器(F3)",
                           Commands::cmCoilRegister,
                           kbF3,
                           hcNoContext,
                           0) +
            *new TMenuItem("~离散输入(02功能码)~寄存器(F4)",
                           Commands::cmDiscreteInputRegister,
                           kbF4,
                           hcNoContext,
                           0) +
            *new TMenuItem("~保持(03,06功能码)~寄存器(F5)",
                           Commands::cmHoldRegister,
                           kbF5,
                           hcNoContext,
                           0) +
            *new TMenuItem("~输入(04功能码)~寄存器(F6)",
                           Commands::cmInputRegister,
                           kbF6,
                           hcNoContext,
                           0) +
            *new TMenuItem("~退~出(Esc)", cmQuit, kbEsc, hcNoContext, 0)));
    return menuBar;
}

void TApp::handleEvent(TEvent &event)
{
    auto handleDialog = [&](auto &dialog)
    {
        dialog->father = this;
        // dialog->setClient(client);
        (void)deskTop->insert(dialog);
        if (validView(dialog))
        {
            dialog->flags &= ~wfMove; // 禁止移动
            (void)deskTop->execView(dialog);
            destroy(dialog);
        }
    };

    TRect r = getExtent();
    int midX = size.x / 2;
    int midY = size.y / 2;

    auto makeTitle = [&](std::string title)
    {
        switch (currentConnectType)
        {
        case ConnectType::None:
            title += ", 当前连接: 无连接";
            break;
        case ConnectType::RTU:
        {
            auto info = SingleModbusRtuClient::getCurrentInfo();
            title += fmt::format(", 当前连接: Modbus 串口, {}", info.port);
            break;
        }
        case ConnectType::TCP:
        {
            auto ip = SingleModbusTcpClient::getCurrentIp();
            auto port = SingleModbusTcpClient::getCurrentPort();
            title += fmt::format(", 当前连接: Modbus TCP, {}:{}", ip, port);
            break;
        }
        default:
            break;
        }
        return title;
    };

    TApplication::handleEvent(event);
    if (event.what == evCommand)
    {
        switch (event.message.command)
        {
        case Commands::cmConnectSerailServer:
        {
            connectRtuViewDialog = new ConnectRtuViewDialog(TRect(midX - 30, midY - 8, midX + 30, midY + 8), "连接Modbus串口");
            handleDialog(connectRtuViewDialog);
            clearEvent(event);
            break;
        }
        case Commands::cmConnectTcpServer:
        {
            connectTcpViewDialog = new ConnectTcpViewDialog(TRect(midX - 30, midY - 8, midX + 30, midY + 8), "连接ModbusTCP服务器");
            handleDialog(connectTcpViewDialog);
            clearEvent(event);
            break;
        }
        case Commands::cmCoilRegister:
        {
            currentRegisterType = RegisterType::Coil;
            std::string title = makeTitle("线圈寄存器");
            coilRegisterDialog = new ModbusViewDialog(r, title.c_str());
            handleDialog(coilRegisterDialog);
            clearEvent(event);
            break;
        }
        case Commands::cmDiscreteInputRegister:
        {
            currentRegisterType = RegisterType::DiscreteInput;
            std::string title = makeTitle("离散输入寄存器");
            discreteInputRegisterDialog = new ModbusViewDialog(r, title.c_str());
            handleDialog(discreteInputRegisterDialog);
            clearEvent(event);
            break;
        }
        case Commands::cmHoldRegister:
        {
            currentRegisterType = RegisterType::Hold;
            std::string title = makeTitle("保持寄存器");
            holdRegisterDialog = new ModbusViewDialog(r, title.c_str());
            handleDialog(holdRegisterDialog);
            clearEvent(event);
            break;
        }
        case Commands::cmInputRegister:
        {
            currentRegisterType = RegisterType::Input;
            std::string title = makeTitle("输入寄存器");
            inputRegisterDialog = new ModbusViewDialog(r, title.c_str());
            handleDialog(inputRegisterDialog);
            clearEvent(event);
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

void TApp::idle() { TProgram::idle(); }

int main(int argc, char *argv[])
{
    TApp myApp;
    myApp.run();
    return 0;
}