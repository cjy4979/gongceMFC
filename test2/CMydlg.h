#pragma once


// CMydlg 对话框

class CMydlg : public CDialog
{
	DECLARE_DYNAMIC(CMydlg)

public:
	CMydlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMydlg();
	int m_pca; 
	double samp_freq;
	void Set_EditBox_Content(int idc, int val);
	void Set_EditBox_Content(int idc, double val);

	int  Get_EditBox_Content_int(int idc);
	double Get_EditBox_Content_double(int idc);



// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
