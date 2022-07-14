#pragma once


// Colordlg 对话框

class Colordlg : public CDialog
{
	DECLARE_DYNAMIC(Colordlg)

public:
	Colordlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Colordlg();
	int r;
	int g;
	int b;
	void Set_EditBox_Content(int idc, int val);

	int  Get_EditBox_Content_int(int idc);


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedColorcancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
