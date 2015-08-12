
// CH10_GraphicView.cpp : CCH10_GraphicView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CH10_Graphic.h"
#endif

#include "CH10_GraphicDoc.h"
#include "CH10_GraphicView.h"

#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH10_GraphicView

IMPLEMENT_DYNCREATE(CCH10_GraphicView, CView)

BEGIN_MESSAGE_MAP(CCH10_GraphicView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DOT, &CCH10_GraphicView::OnDot)
	ON_COMMAND(IDM_ELLIPSE, &CCH10_GraphicView::OnEllipse)
	ON_COMMAND(IDM_LINE, &CCH10_GraphicView::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CCH10_GraphicView::OnRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_SETTING, &CCH10_GraphicView::OnSetting)
	ON_COMMAND(IDM_COLOR, &CCH10_GraphicView::OnColor)
	ON_COMMAND(IDM_FONT, &CCH10_GraphicView::OnFont)
END_MESSAGE_MAP()

// CCH10_GraphicView 构造/析构

CCH10_GraphicView::CCH10_GraphicView()
{
	// TODO: 在此处添加构造代码

	m_nDrawType = 0;
	m_nLineWidth = 0;
	m_nLineStyle = 0;
	m_clr = RGB(255, 0, 0);
	m_strFontName = _T("");
}

CCH10_GraphicView::~CCH10_GraphicView()
{
}

BOOL CCH10_GraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCH10_GraphicView 绘制

//void CCH10_GraphicView::OnDraw(CDC* /*pDC*/)
void CCH10_GraphicView::OnDraw(CDC* pDC)
{
	CCH10_GraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CFont *pOldFont = pDC->SelectObject(&m_font);
	pDC->TextOutW(0, 0, m_strFontName);
	pDC->SelectObject(pOldFont);
}


// CCH10_GraphicView 打印

BOOL CCH10_GraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCH10_GraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCH10_GraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCH10_GraphicView 诊断

#ifdef _DEBUG
void CCH10_GraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CCH10_GraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH10_GraphicDoc* CCH10_GraphicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH10_GraphicDoc)));
	return (CCH10_GraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH10_GraphicView 消息处理程序


void CCH10_GraphicView::OnDot()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType = 1;
}


void CCH10_GraphicView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType = 4;
}


void CCH10_GraphicView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType = 2;
}


void CCH10_GraphicView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType = 3;
}


void CCH10_GraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CCH10_GraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);
	//CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	//CPen pen(PS_SOLID, m_nLineWidth, RGB(255, 0, 0));
	//CPen pen(m_nLineStyle, m_nLineWidth, RGB(255, 0, 0));
	CPen pen(m_nLineStyle, m_nLineWidth, m_clr);
	dc.SelectObject(&pen);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = dc.SelectObject(pBrush);

	switch (m_nDrawType)
	{
	case 1:
		//dc.SetPixel(point, RGB(255, 0, 0));
		dc.SetPixel(point, m_clr);
		break;

	case 2:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;

	case 3:
		dc.Rectangle(CRect(m_ptOrigin, point));
		break;

	case 4:
		dc.Ellipse(CRect(m_ptOrigin, point));
		break;

	}

	dc.SelectObject(pOldBrush);

	CView::OnLButtonUp(nFlags, point);
}


void CCH10_GraphicView::OnSetting()
{
	// TODO: 在此添加命令处理程序代码

	CSettingDlg dlg;
	dlg.m_nLineWidth = m_nLineWidth;
	dlg.m_nLineStyle = m_nLineStyle;
	if (IDOK == dlg.DoModal())
	{
		m_nLineWidth = dlg.m_nLineWidth;
		m_nLineStyle = dlg.m_nLineStyle;
	}
}


void CCH10_GraphicView::OnColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg;
	//dlg.m_cc.Flags = CC_RGBINIT;
	//dlg.m_cc.Flags |= CC_RGBINIT;		// lint: 不需要添加此属性也可以正常选择颜色。
	//dlg.m_cc.Flags |= CC_RGBINIT | CC_FULLOPEN;
	CString str;
	str.Format(_T("flag = %x"), dlg.m_cc.Flags);
	MessageBox(str);
	dlg.m_cc.rgbResult = m_clr;
	if (IDOK == dlg.DoModal())
	{
		m_clr = dlg.m_cc.rgbResult;
	}
}


void CCH10_GraphicView::OnFont()
{
	// TODO: 在此添加命令处理程序代码
	CFontDialog dlg;
	if (IDOK == dlg.DoModal())
	{
		if (m_font.m_hObject)
		{
			m_font.DeleteObject();
		}
		m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
		m_strFontName = dlg.m_cf.lpLogFont->lfFaceName;
	}

	Invalidate();
}
