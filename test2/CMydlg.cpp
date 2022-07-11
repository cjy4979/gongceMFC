// CMydlg.cpp: 实现文件
//

#include "pch.h"
#include "test2.h"
#include "CMydlg.h"
#include "afxdialogex.h"


// CMydlg 对话框

IMPLEMENT_DYNAMIC(CMydlg, CDialog)

CMydlg::CMydlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CMydlg::~CMydlg()
{
}

void CMydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMydlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CMydlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMydlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMydlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMydlg 消息处理程序


void CMydlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMydlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}


void CMydlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
