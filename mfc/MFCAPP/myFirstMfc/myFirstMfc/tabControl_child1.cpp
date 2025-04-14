// tabControl_child1.cpp: 实现文件
//

#include "pch.h"
#include "myFirstMfc.h"
#include "tabControl_child1.h"
#include "afxdialogex.h"


// tabControl_child1 对话框

IMPLEMENT_DYNAMIC(tabControl_child1, CDialogEx)

tabControl_child1::tabControl_child1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TabControl_Child1, pParent)
{

}

tabControl_child1::~tabControl_child1()
{
}

void tabControl_child1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(tabControl_child1, CDialogEx)
END_MESSAGE_MAP()


// tabControl_child1 消息处理程序
