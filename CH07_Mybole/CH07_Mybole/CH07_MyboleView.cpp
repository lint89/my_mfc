
// CH07_MyboleView.cpp : CCH07_MyboleView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DIALOG, &CCH07_MyboleView::OnDialog)
END_MESSAGE_MAP()

// CCH07_MyboleView 构造/析构

CCH07_MyboleView::CCH07_MyboleView()
{
	// TODO: 在此处添加构造代码

}

CCH07_MyboleView::~CCH07_MyboleView()
{
}

BOOL CCH07_MyboleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCH07_MyboleView 绘制

void CCH07_MyboleView::OnDraw(CDC* /*pDC*/)
{
	CCH07_MyboleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCH07_MyboleView 打印

BOOL CCH07_MyboleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCH07_MyboleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCH07_MyboleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCH07_MyboleView 诊断

#ifdef _DEBUG
void CCH07_MyboleView::AssertValid() const
{
	CView::AssertValid();
}

void CCH07_MyboleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH07_MyboleDoc* CCH07_MyboleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH07_MyboleDoc)));
	return (CCH07_MyboleDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH07_MyboleView 消息处理程序


void CCH07_MyboleView::OnDialog()
{
	// TODO: 在此添加命令处理程序代码
	CTestDlg dlg;
	dlg.DoModal();
}
