
// CH07_MyboleView.h : CCH07_MyboleView 类的接口
//

#pragma once


class CCH07_MyboleView : public CView
{
protected: // 仅从序列化创建
	CCH07_MyboleView();
	DECLARE_DYNCREATE(CCH07_MyboleView)

// 特性
public:
	CCH07_MyboleDoc* GetDocument() const;

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
	virtual ~CCH07_MyboleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDialog();
};

#ifndef _DEBUG  // CH07_MyboleView.cpp 中的调试版本
inline CCH07_MyboleDoc* CCH07_MyboleView::GetDocument() const
   { return reinterpret_cast<CCH07_MyboleDoc*>(m_pDocument); }
#endif

