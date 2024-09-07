#pragma once
#include <string>
#include <vector>
#include <memory>
#include <tvision/tv.h>
#include "sprdview.h"

class DataViewDialog : public TListViewDialog
{
public:
    DataViewDialog(const TRect &trect, const char *aTitle);
    ~DataViewDialog() = default;

    ListRec getListRec(bool show, auto val);
    void initRegisterListData(int startAddr, std::vector<int> registerDataList);

    void clearListViewDialog();
    void setColumnWidth() override;
    void setDecimalPoint() override;
    void setHeadText() override;
    void initListViewDialog() override;
    void handleEvent(TEvent &event) override;
    virtual TPalette &getPalette() const override;

public:
    TRect trect;
};