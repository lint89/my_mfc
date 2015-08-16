
// CH05_TextView.cpp : CCH05_TextView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CH05_Text.h"
#endif

#include "CH05_TextDoc.h"
#include "CH05_TextView.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH05_TextView

IMPLEMENT_DYNCREATE(CCH05_TextView, CView)

BEGIN_MESSAGE_MAP(CCH05_TextView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CCH05_TextView 构造/析构

CCH05_TextView::CCH05_TextView()
{
	// TODO: 在此处添加构造代码

	m_strLine = _T("");
	m_ptOrigin = 0;
}

CCH05_TextView::~CCH05_TextView()
{
}

BOOL CCH05_TextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCH05_TextView 绘制

//void CCH05_TextView::OnDraw(CDC* /*pDC*/)
void CCH05_TextView::OnDraw(CDC* pDC)
{
	CCH05_TextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//CString str(_T("VC++ 深入编程"));
	////CString str;
	////str = _T("VC++ 深入编程");
	//pDC->TextOutW(50, 50, str);

	/* 使用字符串资源 */
	//CString str;
	//str.LoadStringW(IDS_STRINGVC);
	//pDC->TextOutW(0, 200, str);

	/* 路径 */
	CString str;
	//CSize sz = pDC->GetTextExtent(str);
	str.LoadStringW(IDS_STRINGVC);
	CSize sz = pDC->GetTextExtent(str);
	pDC->TextOutW(50, 50, str);

	pDC->BeginPath();
	pDC->Rectangle(50, 50, 50 + sz.cx, 50 + sz.cy);
	pDC->EndPath();
}


// CCH05_TextView 打印

BOOL CCH05_TextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCH05_TextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCH05_TextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCH05_TextView 诊断

#ifdef _DEBUG
void CCH05_TextView::AssertValid() const
{
	CView::AssertValid();
}

void CCH05_TextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH05_TextDoc* CCH05_TextView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH05_TextDoc)));
	return (CCH05_TextDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH05_TextView 消息处理程序


int CCH05_TextView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	/* 创建文本插入符 */
	//CreateSolidCaret(20, 100);
	//ShowCaret();

	//CClientDC dc(this);
	//TEXTMETRIC tm;
	//dc.GetTextMetrics(&tm);
	//CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	//ShowCaret();

	/* 创建图形插入符 */
	//CBitmap bitmap;	// 局部变量，析构是被销毁，需修改为成员变量
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CreateCaret(&bitmap);
	ShowCaret();

	return 0;
}


void CCH05_TextView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_strLine.Empty();
	m_ptOrigin = point;

	CView::OnLButtonDown(nFlags, point);
}


void CCH05_TextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d == nChar)
	{
		m_strLine.Empty();
		m_ptOrigin.y += tm.tmHeight;
	}
	else if (0x08 == nChar)
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOutW(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() -1);
		dc.SetTextColor(clr);
	}
	else
	{
		m_strLine += (UCHAR)nChar;
	}

	dc.TextOutW(m_ptOrigin.x, m_ptOrigin.y, m_strLine);

	CSize sz = dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x = m_ptOrigin.x + sz.cx;
	pt.y = m_ptOrigin.y;
	SetCaretPos(pt);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
