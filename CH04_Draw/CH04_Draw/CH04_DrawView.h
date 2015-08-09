
// CH04_DrawView.h : CCH04_DrawView 类的接口
//

#pragma once
#include "atltypes.h"


class CCH04_DrawView : public CView
{
protected: // 仅从序列化创建
	CCH04_DrawView();
	DECLARE_DYNCREATE(CCH04_DrawView)

// 特性
public:
	CCH04_DrawDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCH04_DrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	BOOL m_bDraw;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	CPoint m_ptOld;
};

#ifndef _DEBUG  // CH04_DrawView.cpp 中的调试版本
inline CCH04_DrawDoc* CCH04_DrawView::GetDocument() const
   { return reinterpret_cast<CCH04_DrawDoc*>(m_pDocument); }
#endif

