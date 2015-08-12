
// CH10_GraphicView.cpp : CCH10_GraphicView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CCH10_GraphicView ����/����

CCH10_GraphicView::CCH10_GraphicView()
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCH10_GraphicView ����

//void CCH10_GraphicView::OnDraw(CDC* /*pDC*/)
void CCH10_GraphicView::OnDraw(CDC* pDC)
{
	CCH10_GraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CFont *pOldFont = pDC->SelectObject(&m_font);
	pDC->TextOutW(0, 0, m_strFontName);
	pDC->SelectObject(pOldFont);
}


// CCH10_GraphicView ��ӡ

BOOL CCH10_GraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCH10_GraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCH10_GraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCH10_GraphicView ���

#ifdef _DEBUG
void CCH10_GraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CCH10_GraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH10_GraphicDoc* CCH10_GraphicView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH10_GraphicDoc)));
	return (CCH10_GraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH10_GraphicView ��Ϣ�������


void CCH10_GraphicView::OnDot()
{
	// TODO: �ڴ���������������
	m_nDrawType = 1;
}


void CCH10_GraphicView::OnEllipse()
{
	// TODO: �ڴ���������������
	m_nDrawType = 4;
}


void CCH10_GraphicView::OnLine()
{
	// TODO: �ڴ���������������
	m_nDrawType = 2;
}


void CCH10_GraphicView::OnRectangle()
{
	// TODO: �ڴ���������������
	m_nDrawType = 3;
}


void CCH10_GraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CCH10_GraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO: �ڴ���������������

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
	// TODO: �ڴ���������������
	CColorDialog dlg;
	//dlg.m_cc.Flags = CC_RGBINIT;
	//dlg.m_cc.Flags |= CC_RGBINIT;		// lint: ����Ҫ��Ӵ�����Ҳ��������ѡ����ɫ��
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
	// TODO: �ڴ���������������
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
