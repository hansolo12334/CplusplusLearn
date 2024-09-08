
// myFirstMfcDlg.h: 头文件
//
#pragma once

#include<vector>

#include "tabControl_child1.h"
#include "tabControl_child2.h"

// CmyFirstMfcDlg 对话框
class CmyFirstMfcDlg : public CDialogEx
{
// 构造
public:
	CmyFirstMfcDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYFIRSTMFC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

//自定义的控件
private:
    std::vector<CDialogEx*> m_tab_pages;

    int  m_current_page = 0;
    tabControl_child1 m_tab_page1;
    tabControl_child2 m_tab_page2;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    //afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedButton1();
    afx_msg void OnEnChangeLineeditTest();
    afx_msg void OnBnClickedMainBtOk();
private:
    CTabCtrl m_tab;
public:
    //tab页面切换事件
    afx_msg void OnSelectTabChange(NMHDR *pNMHDR, LRESULT *pResult);
};
