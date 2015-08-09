
// CH04_DrawView.cpp : CCH04_DrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CH04_Draw.h"
#endif

#include "CH04_DrawDoc.h"
#include "CH04_DrawView.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH04_DrawView

IMPLEMENT_DYNCREATE(CCH04_DrawView, CView)

BEGIN_MESSAGE_MAP(CCH04_DrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CCH04_DrawView 构造/析构

CCH04_DrawView::CCH04_DrawView()
	: m_ptOrigin(0),
	m_ptOld(0)
{
	// TODO: 在此处添加构造代码
	m_bDraw = FALSE;

}

CCH04_DrawView::~CCH04_DrawView()
{
}

BOOL CCH04_DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCH04_DrawView 绘制

void CCH04_DrawView::OnDraw(CDC* /*pDC*/)
{
	CCH04_DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCH04_DrawView 打印

BOOL CCH04_DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCH04_DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCH04_DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCH04_DrawView 诊断

#ifdef _DEBUG
void CCH04_DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CCH04_DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH04_DrawDoc* CCH04_DrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH04_DrawDoc)));
	return (CCH04_DrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH04_DrawView 消息处理程序


void CCH04_DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bDraw = TRUE;
	m_ptOrigin = point;
	m_ptOld = point;
	CView::OnLButtonDown(nFlags, point);
}


#if 0
void CCH04_DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	/* 利用SDK全局函数实现画线功能 */
	//HDC hdc;
	//hdc = ::GetDC(m_hWnd);
	//MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//LineTo(hdc, point.x, point.y);
	//::ReleaseDC(m_hWnd, hdc);

	/* 利用MFC的CDC类实现画线功能 */
	//CDC* pDC = GetDC();
	//pDC->MoveTo(m_ptOrigin);
	//pDC->LineTo(point);
	//ReleaseDC(pDC);

	/* 利用MFC的CClientDC类实现画线功能 */
	//CClientDC dc(this);
	//// 获得view类的父窗口类CMainFrame类，实现在工具栏中画线
	////CClientDC dc(GetParent());	
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);

	/* 利用MFC的CWindowDC类实现画线功能 */
	//CWindowDC dc(this);
	////CClientDC dc(GetParent());	
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);

	/* 绘制彩色线条 */
	//CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	////CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
	////CPen pen(PS_DASH, 1, RGB(255, 0, 0));
	//CClientDC dc(this);
	//CPen* pOldPen = dc.SelectObject(&pen);
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//dc.SelectObject(pOldPen);

	/* 使用画刷绘图 */
	/* 简单画刷 */
	//CBrush brush(RGB(255, 0, 0));
	//CClientDC dc(this);
	//dc.FillRect(CRect(m_ptOrigin, point), &brush);

	/* 位图画刷 */
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//CBrush brush(&bitmap);
	//CClientDC dc(this);
	//dc.FillRect(CRect(m_ptOrigin, point), &brush);

	/* 透明画刷 */
	//CClientDC dc(this);
	//dc.Rectangle(CRect(m_ptOrigin, point));

	CClientDC dc(this);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = dc.SelectObject(pBrush);
	dc.Rectangle(CRect(m_ptOrigin, point));
	dc.SelectObject(pOldBrush);

	CView::OnLButtonUp(nFlags, point);
}
#endif


void CCH04_DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bDraw = FALSE;   
}



void CCH04_DrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/* 绘制连续线条 */
	CClientDC dc(this);
	//dc.SetROP2(R2_BLACK);		// 指定绘图模式
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *pOldPen = dc.SelectObject(&pen);

	if (m_bDraw == TRUE)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		//m_ptOrigin = point;	// 注释后，绘制扇形
		dc.LineTo(m_ptOld);
		m_ptOld = point;
	}

	CView::OnMouseMove(nFlags, point);
}
