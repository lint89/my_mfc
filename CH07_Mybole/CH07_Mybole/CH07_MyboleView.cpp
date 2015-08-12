
// CH07_MyboleView.cpp : CCH07_MyboleView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "CH07_Mybole.h"
#endif

#include "CH07_MyboleDoc.h"
#include "CH07_MyboleView.h"

#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH07_MyboleView

IMPLEMENT_DYNCREATE(CCH07_MyboleView, CView)

BEGIN_MESSAGE_MAP(CCH07_MyboleView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DIALOG, &CCH07_MyboleView::OnDialog)
END_MESSAGE_MAP()

// CCH07_MyboleView ����/����

CCH07_MyboleView::CCH07_MyboleView()
{
	// TODO: �ڴ˴���ӹ������

}

CCH07_MyboleView::~CCH07_MyboleView()
{
}

BOOL CCH07_MyboleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCH07_MyboleView ����

void CCH07_MyboleView::OnDraw(CDC* /*pDC*/)
{
	CCH07_MyboleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CCH07_MyboleView ��ӡ

BOOL CCH07_MyboleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCH07_MyboleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCH07_MyboleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCH07_MyboleView ���

#ifdef _DEBUG
void CCH07_MyboleView::AssertValid() const
{
	CView::AssertValid();
}

void CCH07_MyboleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH07_MyboleDoc* CCH07_MyboleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH07_MyboleDoc)));
	return (CCH07_MyboleDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH07_MyboleView ��Ϣ�������


void CCH07_MyboleView::OnDialog()
{
	// TODO: �ڴ���������������
	CTestDlg dlg;
	dlg.DoModal();
}
