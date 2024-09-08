
// myFirstMfcDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "myFirstMfc.h"
#include "myFirstMfcDlg.h"
#include "afxdialogex.h"

#include "CDlgShowPic.h"

#include<iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmyFirstMfcDlg 对话框



CmyFirstMfcDlg::CmyFirstMfcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYFIRSTMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmyFirstMfcDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CmyFirstMfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

    ON_BN_CLICKED(ID_MAIN_BT_OK, &CmyFirstMfcDlg::OnBnClickedMainBtOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CmyFirstMfcDlg::OnBnClickedButton1)
    ON_EN_CHANGE(IDC_LINEEDIT_TEST, &CmyFirstMfcDlg::OnEnChangeLineeditTest)
    ON_BN_CLICKED(ID_MAIN_BT_OK, &CmyFirstMfcDlg::OnBnClickedMainBtOk)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CmyFirstMfcDlg::OnSelectTabChange)
END_MESSAGE_MAP()


// CmyFirstMfcDlg 消息处理程序

BOOL CmyFirstMfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

    //初始化 tab control (tab widget)
    m_tab.InsertItem(0, _T("页面1"));
    m_tab.InsertItem(1, _T("页面2"));

    //在tab页面中创建对话框
    m_tab_page1.Create(IDD_TabControl_Child1, &m_tab);
    m_tab_page2.Create(IDD_TabControl_Child2, &m_tab);

    //设置在tab中显示的范围
    CRect rc;
    m_tab.GetClientRect(rc);

    rc.top += 30;
    rc.bottom -= 0;
    rc.left += 0;
    rc.right -= 0;

    m_tab_page1.MoveWindow(&rc);
    m_tab_page2.MoveWindow(&rc);

    m_tab_pages.push_back(&m_tab_page1);
    m_tab_pages.push_back(&m_tab_page2);

    m_tab_page1.ShowWindow(SW_SHOW);
    m_tab_page2.ShowWindow(SW_HIDE);

    m_current_page = 0;



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmyFirstMfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmyFirstMfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmyFirstMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmyFirstMfcDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
    std::cout << "测试按钮点击\n";
    //以模态方式运行
    CDlgShowPic picDlg;
    picDlg.DoModal();


}


void CmyFirstMfcDlg::OnEnChangeLineeditTest()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
    CStatic* pWnd = (CStatic*)GetDlgItem(IDC_LINEEDIT_TEST);
    std::cout << "获取lineEditTest的句柄: " << pWnd << '\n';

    CString currentContent;
    pWnd->GetWindowText(currentContent);
    std::cout << "当前内容: " << CT2A(currentContent.GetString()) << '\n';
    

}


void CmyFirstMfcDlg::OnBnClickedMainBtOk()
{
    // TODO: 在此添加控件通知处理程序代码
    std::cout << "ok\n";
}


void CmyFirstMfcDlg::OnSelectTabChange(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: 在此添加控件通知处理程序代码
    
    std::cout << "页面切换\n";

    //隐藏之前的页面
    m_tab_pages[m_current_page]->ShowWindow(SW_HIDE);
    //获取当前页面索引
    m_current_page=m_tab.GetCurSel();
    //显示当前页面
    m_tab_pages[m_current_page]->ShowWindow(SW_SHOW);

    *pResult = 0;

}
