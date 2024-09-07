#pragma once
#include <string>
#include <vector>
#include <memory>
#include <tvision/tv.h>
#include "data_view.h"
#include "message_def.h"

struct ReadModule
{
    // 标题
    TStaticText *title;
    // 从机地址
    TStaticText *rtuAddrText;
    TInputLine *rtuAddrEditLine;
    // 起始寄存器地址
    TStaticText *startAddressText;
    TInputLine *startAddressEditLine;
    // 结束寄存器地址
    TStaticText *endAddressText;
    TInputLine *endAddressEditLine;
    // 按钮
    TButton *searchButton;
};

struct WriteModule
{
    // 标题
    TStaticText *title;
    // 从机地址
    TStaticText *rtuAddrText;
    TInputLine *rtuAddrEditLine;
    // 地址
    TStaticText *addressText;
    TInputLine *addressEditLine;
    // 值
    TStaticText *valueText;
    TInputLine *valueEditLine;
    // 按钮
    TButton *writeButton;
};

class ModbusViewDialog : public TDialog
{
public:
    ModbusViewDialog(const TRect &trect, const char *aTitle);
    ~ModbusViewDialog() = default;

    // virtual void draw() override;
    void initReadDataModule();  // 加载读取数据模块
    void initWriteDataModule(); // 加载写入数据模块
    void loadDataViewDialog(int startAddr, std::vector<int> registerDataList);

    void searchData(); // 搜索数据
    void writeData();  // 写入数据
    void handleEvent(TEvent &event) override;
    TPalette &getPalette() const override;

public:
    TApplication *father;
    TRect trect;
    std::shared_ptr<ModbusTcpClient> client;
    ReadModule readModule;
    WriteModule writeModule;
    // 数据界面
    DataViewDialog *dataViewDialog;
};