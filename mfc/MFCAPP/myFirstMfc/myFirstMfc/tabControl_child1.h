#pragma once


// tabControl_child1 对话框

class tabControl_child1 : public CDialogEx
{
	DECLARE_DYNAMIC(tabControl_child1)

public:
	tabControl_child1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~tabControl_child1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TabControl_Child1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
