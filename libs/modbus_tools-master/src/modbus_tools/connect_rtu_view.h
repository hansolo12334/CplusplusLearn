#pragma once
#include <string>
#include <vector>
#include <memory>
#include <tvision/tv.h>

class ModbusTcpClient;

class ConnectRtuViewDialog : public TDialog
{
public:
    ConnectRtuViewDialog(const TRect &trect, const char *aTitle);
    ~ConnectRtuViewDialog() = default;

    void initDialog();
    void connectServer();
    void handleEvent(TEvent &event) override;
    TPalette &getPalette() const override;

public:
    TApplication *father;
    TRect trect;
    // 设备端口
    TStaticText *portLabel;
    TInputLine *portEditLine;
    // 波特率
    TStaticText *baudRateLabel;
    TInputLine *baudRateEditLine;
    // 数据位
    TStaticText *byteSizeLabel;
    TInputLine *byteSizeEditLine;
    // 奇偶校验
    TStaticText *parityLabel;
    TInputLine *parityEditLine;
    // 停止位
    TStaticText *stopBitsLabel;
    TInputLine *stopBitsEditLine;

    TButton *connectButton;
};