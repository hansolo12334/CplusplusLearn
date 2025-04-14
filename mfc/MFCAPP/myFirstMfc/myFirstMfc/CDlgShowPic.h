#pragma once


// CDlgShowPic 对话框

class CDlgShowPic : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShowPic)

public:
	CDlgShowPic(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgShowPic();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICTURE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedShowPic();
    afx_msg void OnBnClickedCancel();
};
