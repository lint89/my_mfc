
// CH04_DrawView.h : CCH04_DrawView ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CCH04_DrawView : public CView
{
protected: // �������л�����
	CCH04_DrawView();
	DECLARE_DYNCREATE(CCH04_DrawView)

// ����
public:
	CCH04_DrawDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CCH04_DrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // CH04_DrawView.cpp �еĵ��԰汾
inline CCH04_DrawDoc* CCH04_DrawView::GetDocument() const
   { return reinterpret_cast<CCH04_DrawDoc*>(m_pDocument); }
#endif

