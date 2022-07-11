
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
END_MESSAGE_MAP()

// Ctest2View 构造/析构

Ctest2View::Ctest2View() noexcept
{
	// TODO: 在此处添加构造代码
	AZ216_Init(0, 0);
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
	CPen  pen(PS_SOLID, 1, RGB(255, 0, 0));
	///三个参数的意义分别 笔的样式(PenStyle),笔的宽度(PenWidth）和颜色
	CPen* pOldPen = pDC.SelectObject(&pen);
	///把自己设定的笔选入设备上下文（DC）
	///SelectObject()不仅将新pen选入，还返回原来的pen
	///划自己想要划的直线吧
	int StartX(10), StartY(20), EndX(100);
	static int EndY(10);;
	pDC.MoveTo(StartX, StartY);
	pDC.LineTo(EndX, EndY);
	EndY += 10; if (EndY >= 300) EndY = 10;
	/////选回去，免得Memory leak
	pDC.SelectObject(pOldPen);
	//CDC::SetTextColor(RGB(byte Red,byte green,byte blue));
	//Red---红色；green---绿色；blue---蓝色。程序代码片段如下：
	//MFC输出
	//CClientDC pDC(this);
	char buffer[] = "千万里，千万里我追寻着你!";
	pDC.TextOut(100, 100, buffer, sizeof(buffer) - 1);
	CString str;
	str = "可是你并不在意!";
	pDC.SetTextColor(RGB(255, 0, 0));//设置文字颜色为红色
	pDC.TextOut(100, 130, str);

	RECT rect;
	GetClientRect(&rect);
	int width, height;
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
	pDC.MoveTo(0, 0); pDC.LineTo(width, height);
	pDC.MoveTo(0, height); pDC.LineTo(width, 0);

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
	MessageBox("测试添加消息处理函数测试消息框");
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
	int m_pca(1), g_channels(1);
	double sampfreq(10000);
	AZ216(m_pca, g_channels, Ad_Buf, 1024, sampfreq, 0, 0, 0, 0, 0);

	CView::OnTimer(nIDEvent);
	InvalidateRect(NULL);
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
