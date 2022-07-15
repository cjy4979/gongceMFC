// CLoginDailog.cpp: 实现文件
//

#include "pch.h"
#include "test2.h"
#include "CLoginDailog.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CLoginDailog 对话框

IMPLEMENT_DYNAMIC(CLoginDailog, CDialogEx)

CLoginDailog::CLoginDailog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Dialog_Login, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDailog::~CLoginDailog()
{
}

void CLoginDailog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Username, m_user);
	DDX_Text(pDX, IDC_Password, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDailog, CDialogEx)
	ON_BN_CLICKED(IDC_Login, &CLoginDailog::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_Cancel, &CLoginDailog::OnBnClickedCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDailog 消息处理程序


void CLoginDailog::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (m_user.IsEmpty() || m_pwd.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}

	//获取用户值
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	if (name == m_user)
	{
		if (pwd == m_pwd) {
			//关闭当前对话框
			CDialog::OnCancel();
		}
		else {
			MessageBox(TEXT("密码错误"));
		}
	}
	else {
		MessageBox(TEXT("用户名错误"));
	}
}


BOOL CLoginDailog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//默认登陆信息
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_user = name;
	m_pwd = pwd;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDailog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CLoginDailog::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLoginDailog::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}