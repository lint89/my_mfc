
// CH10_GraphicView.h : CCH10_GraphicView 类的接口
//

#pragma once


class CCH10_GraphicView : public CView
{
protected: // 仅从序列化创建
	CCH10_GraphicView();
	DECLARE_DYNCREATE(CCH10_GraphicView)

// 特性
public:
	CCH10_GraphicDoc* GetDocument() const;

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
	virtual ~CCH10_GraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // CH10_GraphicView.cpp 中的调试版本
inline CCH10_GraphicDoc* CCH10_GraphicView::GetDocument() const
   { return reinterpret_cast<CCH10_GraphicDoc*>(m_pDocument); }
#endif

