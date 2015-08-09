
// CH04_DrawView.cpp : CCH04_DrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CCH04_DrawView ����/����

CCH04_DrawView::CCH04_DrawView()
	: m_ptOrigin(0),
	m_ptOld(0)
{
	// TODO: �ڴ˴���ӹ������
	m_bDraw = FALSE;

}

CCH04_DrawView::~CCH04_DrawView()
{
}

BOOL CCH04_DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCH04_DrawView ����

void CCH04_DrawView::OnDraw(CDC* /*pDC*/)
{
	CCH04_DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CCH04_DrawView ��ӡ

BOOL CCH04_DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCH04_DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCH04_DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCH04_DrawView ���

#ifdef _DEBUG
void CCH04_DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CCH04_DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH04_DrawDoc* CCH04_DrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH04_DrawDoc)));
	return (CCH04_DrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH04_DrawView ��Ϣ�������


void CCH04_DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bDraw = TRUE;
	m_ptOrigin = point;
	m_ptOld = point;
	CView::OnLButtonDown(nFlags, point);
}


#if 0
void CCH04_DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	/* ����SDKȫ�ֺ���ʵ�ֻ��߹��� */
	//HDC hdc;
	//hdc = ::GetDC(m_hWnd);
	//MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//LineTo(hdc, point.x, point.y);
	//::ReleaseDC(m_hWnd, hdc);

	/* ����MFC��CDC��ʵ�ֻ��߹��� */
	//CDC* pDC = GetDC();
	//pDC->MoveTo(m_ptOrigin);
	//pDC->LineTo(point);
	//ReleaseDC(pDC);

	/* ����MFC��CClientDC��ʵ�ֻ��߹��� */
	//CClientDC dc(this);
	//// ���view��ĸ�������CMainFrame�࣬ʵ���ڹ������л���
	////CClientDC dc(GetParent());	
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);

	/* ����MFC��CWindowDC��ʵ�ֻ��߹��� */
	//CWindowDC dc(this);
	////CClientDC dc(GetParent());	
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);

	/* ���Ʋ�ɫ���� */
	//CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	////CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
	////CPen pen(PS_DASH, 1, RGB(255, 0, 0));
	//CClientDC dc(this);
	//CPen* pOldPen = dc.SelectObject(&pen);
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//dc.SelectObject(pOldPen);

	/* ʹ�û�ˢ��ͼ */
	/* �򵥻�ˢ */
	//CBrush brush(RGB(255, 0, 0));
	//CClientDC dc(this);
	//dc.FillRect(CRect(m_ptOrigin, point), &brush);

	/* λͼ��ˢ */
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//CBrush brush(&bitmap);
	//CClientDC dc(this);
	//dc.FillRect(CRect(m_ptOrigin, point), &brush);

	/* ͸����ˢ */
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/* ������������ */
	CClientDC dc(this);
	//dc.SetROP2(R2_BLACK);		// ָ����ͼģʽ
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *pOldPen = dc.SelectObject(&pen);

	if (m_bDraw == TRUE)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		//m_ptOrigin = point;	// ע�ͺ󣬻�������
		dc.LineTo(m_ptOld);
		m_ptOld = point;
	}

	CView::OnMouseMove(nFlags, point);
}
