// tabControl_child2.cpp: 实现文件
//

#include "pch.h"
#include "myFirstMfc.h"
#include "tabControl_child2.h"
#include "afxdialogex.h"


// tabControl_child2 对话框

IMPLEMENT_DYNAMIC(tabControl_child2, CDialogEx)

tabControl_child2::tabControl_child2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TabControl_Child2, pParent)
{

}

tabControl_child2::~tabControl_child2()
{
}

void tabControl_child2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(tabControl_child2, CDialogEx)
END_MESSAGE_MAP()


// tabControl_child2 消息处理程序
