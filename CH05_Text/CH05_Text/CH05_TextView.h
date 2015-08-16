
// CH05_TextView.h : CCH05_TextView 类的接口
//

#pragma once


class CCH05_TextView : public CView
{
protected: // 仅从序列化创建
	CCH05_TextView();
	DECLARE_DYNCREATE(CCH05_TextView)

// 特性
public:
	CCH05_TextDoc* GetDocument() const;

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
	virtual ~CCH05_TextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CBitmap bitmap;
	CString m_strLine;
	CPoint m_ptOrigin;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // CH05_TextView.cpp 中的调试版本
inline CCH05_TextDoc* CCH05_TextView::GetDocument() const
   { return reinterpret_cast<CCH05_TextDoc*>(m_pDocument); }
#endif

