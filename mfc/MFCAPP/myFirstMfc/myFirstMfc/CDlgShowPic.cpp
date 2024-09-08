// CDlgShowPic.cpp: 实现文件
//

#include "pch.h"
#include "myFirstMfc.h"
#include "CDlgShowPic.h"
#include "afxdialogex.h"

#include<iostream>
// CDlgShowPic 对话框

IMPLEMENT_DYNAMIC(CDlgShowPic, CDialogEx)

CDlgShowPic::CDlgShowPic(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PICTURE_DIALOG, pParent)
{

}

CDlgShowPic::~CDlgShowPic()
{
}

void CDlgShowPic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgShowPic, CDialogEx)
    ON_BN_CLICKED(IDOK, &CDlgShowPic::OnBnClickedShowPic)
    ON_BN_CLICKED(IDCANCEL, &CDlgShowPic::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgShowPic 消息处理程序


void CDlgShowPic::OnBnClickedShowPic()
{
    // TODO: 在此添加控件通知处理程序代码
    //CDialogEx::OnOK();
    std::cout << "点击！\n";
    std::cout << "设置图片！\n";

 
    CStatic* pWnd = (CStatic*)GetDlgItem(IDC_STATIC_PIC);
    CImage img;
    img.Load(_T("C:\\Users\\韩博\\Pictures\\cat2.jpg"));
    CRect rectPicBP;
    CDC *pDCBP = pWnd->GetDC();
    pWnd->GetClientRect(&rectPicBP);
    pDCBP->SetStretchBltMode(STRETCH_HALFTONE);
    img.Draw(pDCBP->m_hDC, rectPicBP);
    ReleaseDC(pDCBP);
    img.Destroy();

}


void CDlgShowPic::OnBnClickedCancel()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnCancel();
}
