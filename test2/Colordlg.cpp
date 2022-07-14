// Colordlg.cpp: 实现文件
//弃用

#include "pch.h"
#include "test2.h"
#include "Colordlg.h"
#include "afxdialogex.h"


// Colordlg 对话框

IMPLEMENT_DYNAMIC(Colordlg, CDialog)

Colordlg::Colordlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

Colordlg::~Colordlg()
{
}

void Colordlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Colordlg, CDialog)

	ON_BN_CLICKED(IDColorCANCEL, &Colordlg::OnBnClickedColorcancel)
	ON_BN_CLICKED(IDOK , &Colordlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Colordlg 消息处理程序



BOOL Colordlg::OnInitDialog()
{
	// TODO:  在此添加额外的初始化
	Set_EditBox_Content(IDC_EDITR, r);
	Set_EditBox_Content(IDC_EDITG, g);
	Set_EditBox_Content(IDC_EDITB, b);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void Colordlg::Set_EditBox_Content(int idc, int val) {
	CEdit* ptr;
	char ss[100];
	ptr = (CEdit*)GetDlgItem(idc);
	if (ptr != NULL)
	{
		sprintf(ss, "%d", val);
		ptr->SetWindowText(ss);
	}
}

int Colordlg::Get_EditBox_Content_int(int idc) {
	CEdit* ptr;
	char ss[100];
	int ret(0);
	ptr = (CEdit*)GetDlgItem(idc);
	if (ptr != NULL) {
		ptr->GetWindowText(ss, 20);
		ret = atoi(ss);
	}
	return ret;
}




void Colordlg::OnBnClickedColorcancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}




void Colordlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	r = Get_EditBox_Content_int(IDC_EDITR);
	g = Get_EditBox_Content_int(IDC_EDITG);
	b = Get_EditBox_Content_int(IDC_EDITB);
}
