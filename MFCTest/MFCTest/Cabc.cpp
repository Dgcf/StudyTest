// Cabc.cpp: 实现文件
//

#include "pch.h"
#include "MFCTest.h"
#include "Cabc.h"
#include "afxdialogex.h"


// Cabc 对话框

IMPLEMENT_DYNAMIC(Cabc, CDialogEx)

Cabc::Cabc(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Cabc::~Cabc()
{
}

void Cabc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cabc, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cabc::OnBnClickedOk)
END_MESSAGE_MAP()


// Cabc 消息处理程序


void Cabc::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	GetDlgItem(IDC_EDIT1)->GetWindowText(a);
	GetDlgItem(IDC_EDIT2)->GetWindowText(b);
	GetDlgItem(IDC_EDIT3)->GetWindowText(c);
	GetDlgItem(IDC_EDIT4)->GetWindowText(d);
	GetDlgItem(IDC_EDIT5)->GetWindowText(e);

	CDialogEx::OnOK();
}
