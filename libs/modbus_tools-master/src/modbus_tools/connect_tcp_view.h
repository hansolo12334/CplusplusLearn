#pragma once
#include <string>
#include <vector>
#include <memory>
#include <tvision/tv.h>

class ModbusTcpClient;

class ConnectTcpViewDialog : public TDialog
{
public:
    ConnectTcpViewDialog(const TRect &trect, const char *aTitle);
    ~ConnectTcpViewDialog() = default;

    void initDialog();
    void connectServer();
    void handleEvent(TEvent &event) override;
    TPalette &getPalette() const override;

public:
    TApplication *father;
    TRect trect;
    std::shared_ptr<ModbusTcpClient> client;
    // IP
    TStaticText *ipLabel;
    TInputLine *ipEditLine;
    // Port
    TStaticText *portLabel;
    TInputLine *portEditLine;
    // button
    TButton *connectButton;
};