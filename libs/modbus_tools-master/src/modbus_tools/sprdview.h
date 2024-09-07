#pragma once
#include <variant>
#include <vector>
#include <tvision/tv.h>
#include <map>

class TMatrixViewer : public TView
{

public:
    TMatrixViewer(const TRect &bounds, TScrollBar *aHScrollBar, TScrollBar *aVScrollBar, int *aColumnWidth);
    virtual void draw();
    virtual void focusItem(int column, int row);
    virtual TPalette &getPalette() const;
    virtual void getText(char *dest, int column, int row, int maxLen);
    virtual Boolean isSelected(int column, int row);
    virtual void handleEvent(TEvent &event);
    virtual void selectItem(int column, int row);
    void setRange(int aColumns, int aRows);
    virtual void setState(int aState, Boolean enable);
    virtual void focusItemNum(int column, int row);
    int getColumnPosition(int column);
    virtual void shutDown();
    void setEditEnabledByColumn(int column, bool enable);

    TScrollBar *hScrollBar;
    TScrollBar *vScrollBar;
    int leftColumn;
    int topRow;
    int focusedColumn;
    int focusedRow;
    int numColumns;
    int numRows;
    Boolean headingMode;
    int *columnWidth;
    std::map<int, bool> editEnabled;

private:
    virtual const char *streamableName() const { return name; }

protected:
    TMatrixViewer(StreamableInit);
    virtual void write(opstream &);
    virtual void *read(ipstream &);

public:
    static const char *const _NEAR name;
    static TStreamable *build();
};

class THeadingViewBox : public TMatrixViewer
{
public:
    THeadingViewBox(const TRect &bounds,
                    TScrollBar *aHScroller,
                    TScrollBar *aVScroller,
                    std::vector<std::string> textList,
                    int *aColumnWidth);
    virtual void getText(char *dest, int column, int row, int maxLen);

    std::vector<std::string> textList;
};

typedef struct
{
    std::variant<int, double, std::string> val;
    Boolean show;
} ListRec;

class TListViewBox : public TMatrixViewer
{
public:
    TListViewBox(const TRect &bounds,
                 TScrollBar *aHScroller,
                 TScrollBar *aVScroller,
                 std::vector<std::vector<ListRec>> aListData,
                 int *aColumnWidth,
                 int *aDecimalPoint);
    virtual void getText(char *dest, int column, int row, int maxLen);
    void handleEvent(TEvent &event);
    virtual void putData(void *rec);
    std::vector<std::vector<ListRec>> ListData;
    int *decimalPoint; // 小数点位数
};

class TListViewDialog : public TDialog
{
public:
    TListViewDialog(const TRect &trect, const char *aTitle);
    virtual void initListViewDialog();
    virtual void setColumnWidth();
    virtual void setDecimalPoint();
    virtual void setHeadText();
    virtual void handleEvent(TEvent &);
    void setEnableEditColumnRange(int startColumn, int endColumn, bool enable); // 设置第几列至第几列可编辑的状态

private:
    void initScroller();   // 初始化滚动条
    void initHeadingBox(); // 初始化标题栏
    void initListBox();    // 初始化列表栏
    void initInputLine();  // 初始化输入框

public:
    TScrollBar *horzScroller;
    TScrollBar *vertScroller;
    THeadingViewBox *headingBox;
    TListViewBox *listBox;
    TListViewBox *listBoxPtr;
    TInputLine *inputLine;
    TInputLine *itemNumber;
    TRect r;
    std::vector<std::string> aListText;
    std::vector<std::vector<ListRec>> aListData;
    std::vector<int> aColumnWidth;
    std::vector<int> aDecimalPoint;
};
