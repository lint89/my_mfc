
// CH10_GraphicView.h : CCH10_GraphicView ��Ľӿ�
//

#pragma once


class CCH10_GraphicView : public CView
{
protected: // �������л�����
	CCH10_GraphicView();
	DECLARE_DYNCREATE(CCH10_GraphicView)

// ����
public:
	CCH10_GraphicDoc* GetDocument() const;

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
	virtual ~CCH10_GraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDot();
	afx_msg void OnEllipse();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
private:
	UINT m_nDrawType;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
public:
	afx_msg void OnSetting();
private:
	UINT m_nLineWidth;
	UINT m_nLineStyle;
public:
	afx_msg void OnColor();
private:
	COLORREF m_clr;
public:
	afx_msg void OnFont();
private:
	CFont m_font;
	CString m_strFontName;
};

#ifndef _DEBUG  // CH10_GraphicView.cpp �еĵ��԰汾
inline CCH10_GraphicDoc* CCH10_GraphicView::GetDocument() const
   { return reinterpret_cast<CCH10_GraphicDoc*>(m_pDocument); }
#endif

