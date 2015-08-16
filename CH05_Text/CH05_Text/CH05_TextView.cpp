
// CH05_TextView.cpp : CCH05_TextView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CCH05_TextView ����/����

CCH05_TextView::CCH05_TextView()
{
	// TODO: �ڴ˴���ӹ������

	m_strLine = _T("");
	m_ptOrigin = 0;
}

CCH05_TextView::~CCH05_TextView()
{
}

BOOL CCH05_TextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCH05_TextView ����

//void CCH05_TextView::OnDraw(CDC* /*pDC*/)
void CCH05_TextView::OnDraw(CDC* pDC)
{
	CCH05_TextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//CString str(_T("VC++ ������"));
	////CString str;
	////str = _T("VC++ ������");
	//pDC->TextOutW(50, 50, str);

	/* ʹ���ַ�����Դ */
	//CString str;
	//str.LoadStringW(IDS_STRINGVC);
	//pDC->TextOutW(0, 200, str);

	/* ·�� */
	CString str;
	//CSize sz = pDC->GetTextExtent(str);
	str.LoadStringW(IDS_STRINGVC);
	CSize sz = pDC->GetTextExtent(str);
	pDC->TextOutW(50, 50, str);

	pDC->BeginPath();
	pDC->Rectangle(50, 50, 50 + sz.cx, 50 + sz.cy);
	pDC->EndPath();
}


// CCH05_TextView ��ӡ

BOOL CCH05_TextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCH05_TextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCH05_TextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCH05_TextView ���

#ifdef _DEBUG
void CCH05_TextView::AssertValid() const
{
	CView::AssertValid();
}

void CCH05_TextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH05_TextDoc* CCH05_TextView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH05_TextDoc)));
	return (CCH05_TextDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH05_TextView ��Ϣ�������


int CCH05_TextView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	/* �����ı������ */
	//CreateSolidCaret(20, 100);
	//ShowCaret();

	//CClientDC dc(this);
	//TEXTMETRIC tm;
	//dc.GetTextMetrics(&tm);
	//CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	//ShowCaret();

	/* ����ͼ�β���� */
	//CBitmap bitmap;	// �ֲ������������Ǳ����٣����޸�Ϊ��Ա����
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CreateCaret(&bitmap);
	ShowCaret();

	return 0;
}


void CCH05_TextView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	m_strLine.Empty();
	m_ptOrigin = point;

	CView::OnLButtonDown(nFlags, point);
}


void CCH05_TextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
