#define Uses_TListBox
#define Uses_TEvent
#define Uses_TDialog
#define Uses_TInputLine
#define Uses_TScrollBar
#define Uses_TStaticText
#define Uses_TKeys
#define Uses_TWindow
#define Uses_TView
#define Uses_MsgBox
#include <tvision/tv.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
#include <variant>
#include "sprdview.h"

constexpr int cmUpdateItemNumber = 901;

#define cpMatrixViewer "\x1A\x1A\x1B\x1C\x1D\x06"

const char *const _NEAR TMatrixViewer::name = "TMatrixViewer";

TMatrixViewer::TMatrixViewer(const TRect &bounds, TScrollBar *aHScrollBar, TScrollBar *aVScrollBar, int *aColumnWidth)
    : TView(bounds), leftColumn(0), topRow(0), focusedColumn(0), focusedRow(0), numColumns(0), numRows(0), headingMode(False)
{
    int arStep, pgStep;

    columnWidth = aColumnWidth;

    options |= ofFirstClick | ofSelectable;
    eventMask |= evBroadcast;

    if (aVScrollBar != 0)
    {
        pgStep = size.y - 1;
        arStep = 1;
        aVScrollBar->setStep(pgStep, arStep);
    }

    if (aHScrollBar != 0)
        aHScrollBar->setStep(size.x, 1);

    hScrollBar = aHScrollBar;
    vScrollBar = aVScrollBar;
}

void TMatrixViewer::draw()
{
    int i, row, column;
    int normalColor, selectedColor, focusedColor, color;
    TDrawBuffer b;
    uchar scOff;
    int thisWidth;

    focusedColor = getColor(3);  // 选中的颜色
    selectedColor = getColor(4); // 修改数据后按回车键的颜色
    if (headingMode)             // 表头颜色
        normalColor = getColor(6);
    else if ((state & (sfSelected | sfActive)) == (sfSelected | sfActive))
        normalColor = getColor(1);
    else
        normalColor = getColor(2);

    int posColumn = 0;
    for (column = leftColumn; posColumn <= size.x; column++)
    {
        if (column < numColumns)
            thisWidth = *(columnWidth + column);
        else
            thisWidth = size.x - posColumn + 1;

        for (i = 0; i < size.y; i++)
        {
            row = i + topRow;
            if (headingMode)
            {
                color = normalColor;
                scOff = 4;
            }
            else if ((state & (sfSelected | sfActive)) == (sfSelected | sfActive) && focusedRow == row && focusedColumn == column && numRows > 0)
            {
                color = focusedColor;
                setCursor(posColumn + 1, i); // Move the hardware cursor.
                scOff = 0;
            }
            else if (column < numColumns && row < numRows && isSelected(column, row))
            {
                color = selectedColor;
                scOff = 2;
            }
            else
            {
                color = normalColor;
                scOff = 4;
            }

            b.moveChar(0, ' ', color, thisWidth); // Clear draw buffer.
            if (column < numColumns && row < numRows)
            {
                char text[256];
                getText(text, column, row, thisWidth);
                char buf[256];
                memmove(buf, text, thisWidth);
                buf[thisWidth] = EOS;
                b.moveStr(1, buf, color);
                if (showMarkers)
                {
                    b.putChar(0, specialChars[scOff]);
                    b.putChar(thisWidth - 2, specialChars[scOff + 1]);
                }
            }
            else if (i == 0 && column == 0)
            {
                b.moveStr(1, "<empty>", getColor(1));
            }

            if (!headingMode && column < (numColumns - 1) && row < numRows) // 分割线
                b.moveChar(thisWidth - 1, (char)179, getColor(5), 1);

            writeLine(posColumn, i, thisWidth, 1, b);
        }
        // Advance to the next column.
        posColumn += thisWidth;
    }
}

void TMatrixViewer::focusItem(int column, int row)
{

    focusedColumn = column;
    if (hScrollBar != 0)
        hScrollBar->setValue(column);
    if (column < leftColumn)
    {
        leftColumn = column;
    }
    else
    {
        while (getColumnPosition(column + 1) > size.x)
            leftColumn++;
    }

    focusedRow = row;
    if (vScrollBar != 0)
        vScrollBar->setValue(row);
    if (row < topRow)
    {
        topRow = row;
    }
    else
    {
        if (row >= topRow + size.y)
            topRow = row - size.y + 1;
    }

    (void)message(owner, evBroadcast, cmUpdateItemNumber, this);
}

void TMatrixViewer::focusItemNum(int column, int row)
{

    if (column < 0)
    {
        column = 0;
    }
    else
    {
        if (column >= numColumns)
            column = numColumns - 1;
    }

    if (row < 0)
    {
        row = 0;
    }
    else
    {
        if (row >= numRows && numRows > 0)
            row = numRows - 1;
    }

    if (numRows != 0)
        focusItem(column, row);
}

void TMatrixViewer::setEditEnabledByColumn(int column, bool enable) { editEnabled[column] = enable; }

TPalette &TMatrixViewer::getPalette() const
{
    // static TPalette palette(cpBlueDialog, sizeof(cpBlueDialog) - 1);
    static TPalette palette(cpMatrixViewer, sizeof(cpMatrixViewer) - 1);
    return palette;
}

void TMatrixViewer::getText(char *dest, int, int, int) { *dest = EOS; }

Boolean TMatrixViewer::isSelected(int column, int row) { return Boolean((column == focusedColumn) && (row == focusedRow)); }

void TMatrixViewer::handleEvent(TEvent &event)
{
    TPoint mouse;
    int oldRow, newRow;
    int oldColumn, newColumn;
    int count;
    int mouseAutosToSkip = 4;

    TView::handleEvent(event);

    newColumn = oldColumn = focusedColumn;
    newRow = oldRow = focusedRow;

    if (event.what == evMouseDown)
    {
        count = 0;
        do
        {
            mouse = makeLocal(event.mouse.where);
            if (mouseInView(event.mouse.where))
            {
                for (newColumn = leftColumn; (newColumn < numColumns) && (getColumnPosition(newColumn + 1) <= mouse.x);
                     newColumn++)
                    ;
                newRow = mouse.y + topRow;
            }
            else
            {
                if (event.what == evMouseAuto)
                    count++;
                if (count == mouseAutosToSkip)
                {
                    count = 0;
                    if (mouse.x < 0)
                    {
                        newColumn = focusedColumn - 1;
                    }
                    else
                    {
                        if (mouse.x >= size.x)
                            newColumn = focusedColumn + 1;
                    }
                    if (mouse.y < 0)
                    {
                        newRow = focusedRow - 1;
                    }
                    else
                    {
                        if (mouse.y >= size.y)
                            newRow = focusedRow + 1;
                    }
                }
            }
            if (newColumn != oldColumn || newRow != oldRow)
                focusItemNum(newColumn, newRow);
            oldColumn = newColumn;
            oldRow = newRow;
        } while (mouseEvent(event, evMouseMove | evMouseAuto));
        focusItemNum(newColumn, newRow);
        if ((event.mouse.eventFlags & meDoubleClick) && focusedColumn < numColumns && focusedRow < numRows)
        {
            selectItem(focusedColumn, focusedRow);
        }
        clearEvent(event);
    }
    else if (event.what == evKeyDown)
    {
        if (event.keyDown.charScan.charCode == ' ' && focusedColumn < numColumns && focusedRow < numRows)
        {
            selectItem(focusedColumn, focusedRow);
        }
        else
        {
            switch (ctrlToArrow(event.keyDown.keyCode))
            {
            case kbUp:
                newRow = oldRow - 1;
                break;
            case kbDown:
                newRow = oldRow + 1;
                break;
            case kbRight:
                newColumn = oldColumn + 1;
                break;
            case kbLeft:
                newColumn = oldColumn - 1;
                break;
            case kbPgDn:
                newRow = oldRow + size.y;
                break;
            case kbPgUp:
                newRow = oldRow - size.y;
                break;
            case kbHome:
                newRow = topRow;
                newColumn = leftColumn;
                break;
            case kbEnd:
                newRow = topRow + size.y - 1;
                for (newColumn = leftColumn; (newColumn < numColumns) && (getColumnPosition(newColumn + 1) <= size.x);
                     newColumn++)
                    ;
                break;
            case kbCtrlPgDn:
                newRow = numRows - 1;
                break;
            case kbCtrlPgUp:
                newRow = 0;
                break;
            case kbTab:
                newColumn = oldColumn + 1;
                if (newColumn >= numColumns)
                {
                    newRow = oldRow + 1;
                    if (newRow >= numRows)
                        newRow = 0;
                    newColumn = 0;
                }
                break;
            case kbShiftTab:
                if (oldColumn == 0)
                {
                    if (oldRow == 0)
                        oldRow = numRows;
                    newRow = oldRow - 1;
                    oldColumn = numColumns;
                }
                newColumn = oldColumn - 1;
                break;
            default:
                return;
            }
        }
        focusItemNum(newColumn, newRow);
        clearEvent(event);
    }
    else if (event.what == evBroadcast)
    {
        if ((options & ofSelectable) != 0)
        {
            if (event.message.command == cmScrollBarClicked && (event.message.infoPtr == hScrollBar || event.message.infoPtr == vScrollBar))
            {
                select();
            }
            else if (event.message.command == cmScrollBarChanged && (event.message.infoPtr == hScrollBar || event.message.infoPtr == vScrollBar))
            {
                int vVal = vScrollBar ? vScrollBar->value : 0;
                int hVal = hScrollBar ? hScrollBar->value : 0;
                focusItemNum(hVal, vVal);
                drawView();
            }
        }
    }
}

void TMatrixViewer::selectItem(int, int) { (void)message(owner, evBroadcast, cmListItemSelected, this); }

void TMatrixViewer::setRange(int aColumns, int aRows)
{

    numColumns = aColumns;
    if (hScrollBar != 0)
    {
        if (focusedColumn > aColumns)
            focusedColumn = 0;
        hScrollBar->setParams(focusedColumn, 0, aColumns - 1, hScrollBar->pgStep, hScrollBar->arStep);
    }

    numRows = aRows;
    if (vScrollBar != 0)
    {
        if (focusedRow > aRows)
            focusedRow = 0;
        vScrollBar->setParams(focusedRow, 0, aRows - 1, vScrollBar->pgStep, vScrollBar->arStep);
    }
}

void TMatrixViewer::setState(int aState, Boolean enable)
{

    TView::setState(aState, enable);
    if ((aState & (sfSelected | sfActive)) != 0)
    {
        if (hScrollBar != 0)
        {
            if (getState(sfActive))
                hScrollBar->show();
            else
                hScrollBar->hide();
        }
        if (vScrollBar != 0)
        {
            if (getState(sfActive))
                vScrollBar->show();
            else
                vScrollBar->hide();
        }
        drawView();
    }
}

int TMatrixViewer::getColumnPosition(int column)
{

    int position = 0;
    for (int i = leftColumn; i < numColumns; i++)
    {
        if (i == column)
            break;
        position += *(columnWidth + i);
    }
    return (position);
}

void TMatrixViewer::shutDown()
{

    hScrollBar = 0;
    vScrollBar = 0;
    TView::shutDown();
}

void TMatrixViewer::write(opstream &os)
{

    TView::write(os);
    os << hScrollBar << vScrollBar << topRow << focusedRow << numRows;
}

void *TMatrixViewer::read(ipstream &is)
{

    (void)TView::read(is);
    is >> hScrollBar >> vScrollBar >> topRow >> focusedRow >> numRows;
    return this;
}

TStreamable *TMatrixViewer::build() { return new TMatrixViewer(streamableInit); }

TMatrixViewer::TMatrixViewer(StreamableInit)
    : TView(streamableInit)
{
}

constexpr int cmListKeyEnter = 59;

THeadingViewBox::THeadingViewBox(
    const TRect &bounds, TScrollBar *aHScroller, TScrollBar *aVScroller, std::vector<std::string> aListText, int *aColumnWidth)
    : TMatrixViewer(bounds, aHScroller, aVScroller, aColumnWidth)
{

    textList = aListText;
    // 默认只有一行
    int row = 1;
    int col = textList.size();
    setRange(col, row);
    if (aHScroller != 0)
        aHScroller->maxVal = col - 1;
    if (aVScroller != 0)
        aVScroller->maxVal = row - 1;
    headingMode = True;
}

void THeadingViewBox::getText(char *dest, int column, int row, int maxLen)
{
    if (column >= textList.size())
        return;
    std::variant<int, double, std::string> data = textList[column];
    std::visit(
        [&](const auto &value)
        {
            std::stringstream ss;
            ss << std::left << std::setw(maxLen) << value;
            strncpy(dest, ss.str().c_str(), maxLen);
        },
        data);
}

TListViewBox::TListViewBox(const TRect &bounds,
                           TScrollBar *aHScroller,
                           TScrollBar *aVScroller,
                           std::vector<std::vector<ListRec>> aListData,
                           int *aColumnWidth,
                           int *aDecimalPoint)
    : TMatrixViewer(bounds, aHScroller, aVScroller, aColumnWidth)
{

    ListData = aListData;
    columnWidth = aColumnWidth;
    decimalPoint = aDecimalPoint;
    if (aListData.size() == 0 || aListData[0].size() == 0)
        return;
    int row = aListData.size();
    int col = aListData[0].size();
    setRange(col, row);
    if (aHScroller != 0)
        aHScroller->maxVal = col - 1;
    if (aVScroller != 0)
        aVScroller->maxVal = row - 1;
}

// 获取某个单元格的数据
void TListViewBox::getText(char *dest, int column, int row, int maxLen)
{
    if (row >= ListData.size() || column >= ListData[0].size())
        return;
    std::variant<int, double, std::string> data = ListData[row][column].val;
    std::visit(
        [&](auto &&value)
        {
            if (ListData[row][column].show)
            {
                using T = std::decay_t<decltype(value)>;
                if constexpr (std::is_same_v<T, int>)
                {
                    sprintf(dest, "%d", value);
                }
                if constexpr (std::is_same_v<T, double>)
                {
                    sprintf(dest, "%*.*lf", maxLen - 2, *(decimalPoint + column), value);
                }
                else if constexpr (std::is_same_v<T, std::string>)
                {
                    strncpy(dest, value.c_str(), maxLen);
                }
            }
            else
            {
                *dest = EOS;
            }
        },
        data);
}

void TListViewBox::handleEvent(TEvent &event)
{

    if ((event.what == evMouseDown) && (event.mouse.eventFlags & meDoubleClick))
    {
        (void)message(owner, evBroadcast, cmListItemSelected, this);
        clearEvent(event);
    }
    if ((event.what == evKeyDown) && (event.keyDown.keyCode == kbEnter))
    {
        (void)message(owner, evBroadcast, cmListKeyEnter, this);
        clearEvent(event);
    }

    TMatrixViewer::handleEvent(event);
}

void TListViewBox::putData(void *rec)
{
    char *txt;
    txt = (char *)rec;
    if (focusedRow >= ListData.size() || focusedColumn >= ListData[0].size())
        return;
    ListRec &ptr = ListData[focusedRow][focusedColumn];
    while (isspace(*txt))
        strcpy(txt, txt + 1);
    if (*txt == EOS)
    {
        ptr.val = "";
        ptr.show = False;
    }
    else
    {
        if constexpr (std::is_same_v<std::decay_t<decltype(ptr.val)>, double>)
        {
            ptr.val = atof(txt);
        }
        else
        {
            if (txt != nullptr && strlen(txt) > 0)
            {
                std::string str = std::string(txt);
                ptr.val.emplace<std::string>(str);
            }
            else
            {
                ptr.val = "";
            }
        }
        ptr.show = True;
    }
    draw();
}

TListViewDialog::TListViewDialog(const TRect &trect, const char *aTitle)
    : TDialog(trect, aTitle), TWindowInit(TDialog::initFrame)
{
}

void TListViewDialog::handleEvent(TEvent &event)
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
        default:
            break;
        }
        break;
    case evBroadcast: // from List Boxes, infoPtr points to orginator
        switch (event.message.command)
        {
        case cmListItemSelected: // if input line is already showing, hide it
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
        case cmListKeyEnter: // enter key pressed in list box, copy data to inputline
        {
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

void TListViewDialog::setColumnWidth() { aColumnWidth = {10, 15, 15, 15, 10, 15, 15, 20}; }

void TListViewDialog::setDecimalPoint() { aDecimalPoint = {3, 3, 3, 3, 3, 3, 3, 3, 3}; }

void TListViewDialog::setHeadText() { aListText = {"ID", "X", "Y", "Z", "R", "P", "Y", "Name"}; }

void TListViewDialog::initScroller()
{
    // Create a rectangle for scroll box. */
    r = TRect(1, 3, size.x - 2, size.y - 3);
    // 水平滚动条
    horzScroller = new TScrollBar(TRect(r.a.x, r.b.y, r.b.x, r.b.y + 1));
    this->insert(horzScroller);
    // 垂直滚动条
    vertScroller = new TScrollBar(TRect(r.b.x, r.a.y, r.b.x + 1, r.b.y));
    this->insert(vertScroller);
}

void TListViewDialog::initHeadingBox()
{
    constexpr int row = 1;
    headingBox = new THeadingViewBox(TRect(r.a.x, r.a.y - row, r.b.x, r.a.y), horzScroller, 0, aListText, aColumnWidth.data());
    headingBox->growMode = gfGrowHiX;
    this->insert(headingBox);
}

void TListViewDialog::initListBox()
{
    listBox = new TListViewBox(r, horzScroller, vertScroller, aListData, aColumnWidth.data(), aDecimalPoint.data());
    listBox->growMode = gfGrowHiX | gfGrowHiY;
    this->insert(listBox);
}

void TListViewDialog::initInputLine()
{
    constexpr int maxStr = 30;
    inputLine = new TInputLine(TRect(r.a.x, r.a.y, r.a.x + *(aColumnWidth.data()) - 1, r.a.y + 1), maxStr);
    inputLine->hide(); // hide input line
    this->insert(inputLine);

    // Create an (unselectable) box to hold the line number.
    itemNumber = new TInputLine(TRect(r.b.x - 7, r.b.y + 1, r.b.x - 1, r.b.y + 2), 5);
    itemNumber->options &= ~ofSelectable;
    itemNumber->growMode |= gfGrowAll;
    (void)itoa(listBox->focusedRow, itemNumber->data, 10);
    this->insert(itemNumber);
}

void TListViewDialog::setEnableEditColumnRange(int startColumn, int endColumn, bool enable)
{
    if (startColumn < 0 || endColumn >= static_cast<int>(aListText.size()) || startColumn > endColumn)
        return;
    for (int i = startColumn; i <= endColumn; i++)
    {
        listBox->setEditEnabledByColumn(i, enable);
    }
}

void TListViewDialog::initListViewDialog()
{
    setColumnWidth();
    setDecimalPoint();
    setHeadText();
    initScroller();
    initHeadingBox();
    initListBox();
    initInputLine();
}