
// test2View.h: Ctest2View 类的接口
//

#pragma once


class Ctest2View : public CView
{
protected: // 仅从序列化创建
	Ctest2View() noexcept;
	DECLARE_DYNCREATE(Ctest2View)

// 特性
public:
	Ctest2Doc* GetDocument() const;
	short int Ad_Buf[16384];
	int M_Pca;
	double Samp_Freq;
	void TransAD(short* a);//AD转换；
	void sort(short* a);//排序
	double XinHao_yx();//信号有效值；
	double XinHao_Pj();//信号平均值；
	double XinHao_Fz();//信号峰值；
	double XinHao_FFz();//信号峰—峰值。

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Ctest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnScope();
	afx_msg void OnStopscope();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnSetPara();
	afx_msg void OnSample();
};

#ifndef _DEBUG  // test2View.cpp 中的调试版本
inline Ctest2Doc* Ctest2View::GetDocument() const
   { return reinterpret_cast<Ctest2Doc*>(m_pDocument); }
#endif

