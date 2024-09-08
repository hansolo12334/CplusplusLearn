#pragma once


// tabControl_child2 对话框

class tabControl_child2 : public CDialogEx
{
	DECLARE_DYNAMIC(tabControl_child2)

public:
	tabControl_child2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~tabControl_child2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TabControl_Child2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
