
// test2View.cpp: Ctest2View 类的实现
//

#include "pch.h"
#include "framework.h"
#include "AZ316.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test2.h"
#endif

#include "test2Doc.h"
#include "test2View.h"
#include "CMydlg.h"
#include "Colordlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest2View

IMPLEMENT_DYNCREATE(Ctest2View, CView)

BEGIN_MESSAGE_MAP(Ctest2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SCOPE, &Ctest2View::OnScope)
	ON_COMMAND(ID_StopScope, &Ctest2View::OnStopscope)
	ON_WM_TIMER()
	ON_COMMAND(ID_FILE_SAVE, &Ctest2View::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &Ctest2View::OnFileOpen)
	ON_COMMAND(ID_SET_PARA, &Ctest2View::OnSetPara)
	ON_COMMAND(ID_Sample, &Ctest2View::OnSample)
	ON_COMMAND(ID_SetColor, &Ctest2View::OnSetcolor)
END_MESSAGE_MAP()

// Ctest2View 构造/析构

Ctest2View::Ctest2View() noexcept
{
	// TODO: 在此处添加构造代码
	AZ216_Init(0, 0);
	M_Pca = 1; 
	Samp_Freq = 10000.0;
	R = 255;
	G = 0;
	B = 0;
}

Ctest2View::~Ctest2View()
{
}

BOOL Ctest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest2View 绘图

void Ctest2View::OnDraw(CDC* /*pDC*/)
{
	Ctest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	CClientDC pDC(this);
	CPen pen(PS_SOLID, 1, RGB(R, G, B));
	///三个参数的意义分别 笔的样式(PenStyle),笔的宽度(PenWidth）和颜色

	

	CPen* pOldPen = pDC.SelectObject(&pen);

	//绘制波形
	int i;
	RECT rect1;
	GetClientRect(&rect1);
	int ww, hh;
	ww = rect1.right - rect1.left;
	hh = rect1.bottom - rect1.top;
	double deltx = ((double)ww) / 1024.0;
	hh /= 2;
	pDC.MoveTo(0, hh + Ad_Buf[0] * hh / 8192);

	for (i = 0; i < 1024; i++) {
		pDC.LineTo((int)(deltx * ((double)i)), hh + Ad_Buf[i] * hh / 8192);

		// TODO: 在此处为本机数据添加绘制代码
	}
	
	pDC.SetTextColor(RGB(255,0,0));//设置文字颜色为红色

	/////选回去，免得Memory leak
	pDC.SelectObject(pOldPen);

	//坐标轴
	RECT rect; 
	GetClientRect(&rect);
	int width, height;
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
	pDC.MoveTo(0, height / 2); pDC.LineTo(width, height / 2);
	pDC.MoveTo(width / 2, 0); pDC.LineTo(width / 2, height);
	

	//添加信号分析处理结果
	double res[4];
	res[0] = XinHao_yx();//信号有效值；
	res[1] = XinHao_Pj();//信号平均值；
	res[2] = XinHao_Fz();//信号峰值；
	res[3] = XinHao_FFz();//信号峰—峰值。
	char cc[100];
	sprintf(cc, "有效值:%5.1f 平均值:%5.1f 峰值:%5.1f  峰-峰值:%5.1f", res[0], res[1], res[2], res[3]);
	pDC.TextOut(100, 10, cc);
}


// Ctest2View 打印

BOOL Ctest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Ctest2View 诊断

#ifdef _DEBUG
void Ctest2View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest2Doc* Ctest2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest2Doc)));
	return (Ctest2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest2View 消息处理程序


void Ctest2View::OnScope()
{
	// TODO: 在此添加命令处理程序代码
	//MessageBox("测试添加消息处理函数测试消息框");
	SetTimer(10, 100, NULL);
}

UINT_PTR SetTimer(UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc);
BOOL KillTimer(UINT_PTR nIDEvent);

void Ctest2View::OnStopscope()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(10);
}


void Ctest2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*int m_pca(1), g_channels(1);
	double sampfreq(10000);
	AZ216(m_pca, g_channels, Ad_Buf, 1024, sampfreq, 0, 0, 0, 0, 0);*/
	AZ216(M_Pca, 1, Ad_Buf, 1024, Samp_Freq, 0, 0, 0, 0, 0);
	InvalidateRect(NULL);
	CView::OnTimer(nIDEvent);
}


void Ctest2View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	FILE* fp;
	fp = fopen("\\buffer.bin", "wb");
	if (fp != NULL) {
		fwrite(Ad_Buf, sizeof(short int), 16384, fp);
		fclose(fp);
	}
	InvalidateRect(NULL);
}


void Ctest2View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	FILE* fp;
	fp = fopen("\\buffer.bin", "rb");
	if (fp != NULL) {
		fread(Ad_Buf, sizeof(short int), 16384, fp);
		fclose(fp);
	}
	InvalidateRect(NULL);
}


void Ctest2View::OnSetPara()
{
	// TODO: 在此添加命令处理程序代码
	CMydlg hdlg;
	hdlg.m_pca = M_Pca;
	hdlg.samp_freq = Samp_Freq;
	if (hdlg.DoModal() == IDOK) {
		M_Pca = hdlg.m_pca;
		Samp_Freq = hdlg.samp_freq;
	};

}


void Ctest2View::OnSample()
{
	// TODO: 在此添加命令处理程序代码
	AZ216(M_Pca, 1, Ad_Buf, 1024, Samp_Freq, 0, 0, 0, 0, 0);
	InvalidateRect(NULL);
}


double Ctest2View::XinHao_yx()//信号有效值；
{
	double ret(0.0);//ret 为计算后得到的函数值
	double V = XinHao_Pj();
	double ms(0.0); //mean square 均方
	//int Len = sizeof(Ad_Buf) / sizeof(Ad_Buf[0]);
	short* a = new short[1024];
	TransAD(a);
	for (int i = 0; i < 1024; i++) {
		ms = ms + (a[i] - V) * (a[i]- V);
	}
	ret = sqrt(ms / 1024);
	return ret;
}
double Ctest2View::XinHao_Pj()//信号平均值；
{
	double ret(0.0);//ret 为计算后得到的函数值
	double sum(0.0);
	//int Len = sizeof(Ad_Buf) / sizeof(Ad_Buf[0]);
	short* a = new short[1024];
	TransAD(a);
	for (int i = 0; i <1024; i++) {
		sum += a[i];	//AD转换	
	}
	ret = sum / 1024;
	return ret;
}
double Ctest2View::XinHao_Fz()//信号峰值；
{
	double ret(0.0);//ret 为计算后得到的函数值
	double V = XinHao_Pj();
	//int Len = sizeof(Ad_Buf) / sizeof(Ad_Buf[0]);
	short* a = new short[1024];
	TransAD(a);
	short max = 0;
	for (int i = 1; i < 1024; i++)
	{
		if (fabs(a[i] - V) > fabs(a[i - 1] - V)) {
			ret = fabs(a[i]- V);
		}
	}
	return ret;
}
double Ctest2View::XinHao_FFz()//信号峰—峰值。
{
	double ret(0.0);//ret 为计算后得到的函数值
	short* a = new short[1024];
	TransAD(a);
	short max = a[0];
	short min = a[0];
	for (int i = 0; i < 1024; i++)
	{
		if (a[i] > max ) {
			max = a[i];
		}
		if(a[i]< min ) {
			min = a[i];
		}
	}
	ret = max - min;
	return ret;
}

//封装AD转换
//C++ 函数不能直接返回数组，这里采用开辟动态内存的方式
//参考：https://blog.csdn.net/qq_60404548/article/details/124300523?ops_request_misc=&request_id=&biz_id=102&utm_term=C++%20%E5%87%BD%E6%95%B0%E8%BF%94%E5%9B%9E%E6%95%B0%E7%BB%84&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-124300523.nonecase&spm=1018.2226.3001.4187

void Ctest2View::TransAD(short* a)                   //动态分配内存
{	
	//int Len = sizeof(Ad_Buf) / sizeof(Ad_Buf[0]);		//仅前1024通道有效
	for (int i = 0; i <= 1024; i++) {
		a[i] = Ad_Buf[i] * 5000 / 8192 / M_Pca;	//AD转换	
	}
}

void Ctest2View::OnSetcolor()
{
	// TODO: 在此添加命令处理程序代码
	Colordlg hdlg;
	hdlg.DoModal();
	hdlg.r = R;
	hdlg.g = G;
	hdlg.b = B;
	if (hdlg.DoModal() == IDOK) {
		char ss[100];
		R = hdlg.r;
		G = hdlg.g;
		B = hdlg.b;
	};
}
