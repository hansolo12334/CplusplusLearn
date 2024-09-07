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
#include "data_view.h"
#include "log.h"
#include <variant>
#include "spdlog/fmt/fmt.h"
#include "tool.hpp"
constexpr int cmListKeyEnter = 59;
constexpr int cmUpdateItemNumber = 901;

DataViewDialog::DataViewDialog(const TRect &trect, const char *aTitle)
    : TListViewDialog(trect, aTitle), TWindowInit(TDialog::initFrame)
{
}

TPalette &DataViewDialog::getPalette() const
{
    return TView::getPalette();
}

void DataViewDialog::setColumnWidth() { aColumnWidth = {20, 20, 20, 20}; }

void DataViewDialog::setDecimalPoint() { aDecimalPoint = {3, 3, 3, 3}; }

void DataViewDialog::setHeadText()
{
    aListText = {"地址", "16进制地址", "值", "16进制值"};
}

ListRec DataViewDialog::getListRec(bool show, auto val)
{
    ListRec listRec;
    listRec.show = show;
    using V = std::decay_t<decltype(val)>;
    if constexpr (std::is_same_v<V, int>)
    {
        listRec.val.emplace<int>(std::move(val));
    }
    else if constexpr (std::is_same_v<V, double>)
    {
        listRec.val.emplace<double>(std::move(val));
    }
    else if constexpr (std::is_same_v<V, std::string>)
    {
        listRec.val.emplace<std::string>(std::move(val));
    }
    return listRec;
};

void DataViewDialog::initRegisterListData(int startAddr, std::vector<int> registerDataList)
{
    LOG_DEBUG("initRegisterListData start");
    aListData.clear();
    for (int i = 0; i < registerDataList.size(); i++)
    {
        std::vector<ListRec> registerData;
        int addr = startAddr + i;
        registerData.emplace_back(std::move(getListRec(true, addr)));
        auto hexAddr = decToHex(addr);
        registerData.emplace_back(std::move(getListRec(true, processHexStr(hexAddr))));
        registerData.emplace_back(std::move(getListRec(true, registerDataList[i])));
        auto hexData = decToHex(registerDataList[i]);
        registerData.emplace_back(std::move(getListRec(true, processHexStr(hexData))));
        aListData.emplace_back(registerData);
    }
    LOG_DEBUG("initRegisterListData end");
}

void DataViewDialog::clearListViewDialog()
{
    destroy(horzScroller);
    destroy(vertScroller);
    destroy(headingBox);
    destroy(listBox);
    destroy(inputLine);
    destroy(itemNumber);
}

void DataViewDialog::initListViewDialog()
{
    options |= ofCentered;
    TListViewDialog::initListViewDialog();
    setEnableEditColumnRange(0, 4, false); // 设置第0列至第4列不可编辑
}

void DataViewDialog::handleEvent(TEvent &event)
{
    switch (event.what)
    {
    case evMouseDown: // clears input line
        if (inputLine->state & sfSelected)
        {
            inputLine->hide();
        }
        break;
    case evKeyDown:
        switch (event.keyDown.keyCode)
        {
        case kbEsc: // clears input line
            if (inputLine->state & sfSelected)
            {
                inputLine->hide();
                clearEvent(event);
            }
            close();
            clearEvent(event);
            break;
        case kbEnter: // saves input line to list box using listBoxPtr
            if (inputLine->state & sfSelected)
            {
                char work[256];
                inputLine->getData(work);
                listBoxPtr->putData(work);
                inputLine->hide();
                clearEvent(event);
            }
            break;
        case kbF5: // 使用F5键刷新
            initListViewDialog();
            clearEvent(event);
            break;
        default:
            break;
        }
        break;
    case evBroadcast: // from List Boxes, infoPtr points to orginator
        switch (event.message.command)
        {
        case cmListItemSelected:
        { // if input line is already showing, hide it
            if (listBox->editEnabled[listBox->focusedColumn] == false)
            {
                clearEvent(event);
                break;
            }
            if (inputLine->state & sfSelected)
            {
                inputLine->hide();
                clearEvent(event);
            }
            else // show empty input line
            {
                int mouseLocY = ((TListViewBox *)event.message.infoPtr)->cursor.y;
                int mouseLocX = ((TListViewBox *)event.message.infoPtr)->cursor.x;
                listBoxPtr = (TListViewBox *)event.message.infoPtr;
                inputLine->growTo(*(listBoxPtr->columnWidth + listBoxPtr->focusedColumn) - 1, 1);
                inputLine->moveTo(mouseLocX, mouseLocY + 3);
                strcpy(inputLine->data, "");
                inputLine->show();
                clearEvent(event);
            }
            break;
        }
        case cmListKeyEnter: // enter key pressed in list box, copy data to inputline
        {
            if (listBox->editEnabled[listBox->focusedColumn] == false)
            {
                clearEvent(event);
                break;
            }
            int mouseLocY = ((TListViewBox *)event.message.infoPtr)->cursor.y;
            int mouseLocX = ((TListViewBox *)event.message.infoPtr)->cursor.x;
            listBoxPtr = (TListViewBox *)event.message.infoPtr;
            inputLine->growTo(*(listBoxPtr->columnWidth + listBoxPtr->focusedColumn) - 1, 1);
            inputLine->moveTo(mouseLocX, mouseLocY + 3);
            listBoxPtr->getText(inputLine->data, listBoxPtr->focusedColumn, listBoxPtr->focusedRow, inputLine->maxLen);
            inputLine->show();
            clearEvent(event);
            break;
        }
        case cmUpdateItemNumber:
            (void)itoa(listBox->focusedRow, itemNumber->data, 10);
            itemNumber->draw();
            clearEvent(event);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    // Let TDialog handler do it's thing with any remaining events.
    TDialog::handleEvent(event);
}