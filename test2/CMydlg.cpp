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
	char ss[100];
	samp_freq = Get_EditBox_Content_double(IDC_EDIT1);
	m_pca = Get_EditBox_Content_int(IDC_EDIT2);
	sprintf(ss, "m_pca=%d samp_freq=%5.1f", m_pca, samp_freq);
	MessageBox(ss);


}


void CMydlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	samp_freq = Get_EditBox_Content_double(IDC_EDIT1);
	m_pca = Get_EditBox_Content_int(IDC_EDIT2);

}


void CMydlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


BOOL CMydlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	/*Set_EditBox_Content(IDC_EDIT1, 5000.0);
	Set_EditBox_Content(IDC_EDIT2, 1);*/
	Set_EditBox_Content(IDC_EDIT1, samp_freq);
	Set_EditBox_Content(IDC_EDIT2, m_pca);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CMydlg::Set_EditBox_Content(int idc, int val) {
	CEdit* ptr;
	char ss[100];
	ptr = (CEdit*)GetDlgItem(idc);
	if (ptr != NULL)
	{
		sprintf(ss, "%d", val);
		ptr->SetWindowText(ss);
	}
}
void CMydlg::Set_EditBox_Content(int idc, double val) {
	CEdit* ptr;
	char ss[100];
	ptr = (CEdit*)GetDlgItem(idc);
	if (ptr != NULL)
	{
		sprintf(ss, "%5.1f", val);
		ptr->SetWindowText(ss);
	}
}

int CMydlg::Get_EditBox_Content_int(int idc) {
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
double CMydlg::Get_EditBox_Content_double(int idc) {
	CEdit* ptr;
	char ss[100];
	double ret(0.0);
	ptr = (CEdit*)GetDlgItem(idc);
	if (ptr != NULL) {
		ptr->GetWindowText(ss, 20);
		ret = atof(ss);
	}
	return ret;
}

