#pragma once


// CLoginDailog 对话框

class CLoginDailog : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDailog)

public:
	CLoginDailog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLoginDailog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Dialog_Login };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_user;
	CString m_pwd;
public:
	afx_msg void OnBnClickedLogin();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	virtual void OnOK();
	afx_msg void OnClose();
};
