
// CH07_MyboleView.h : CCH07_MyboleView ��Ľӿ�
//

#pragma once


class CCH07_MyboleView : public CView
{
protected: // �������л�����
	CCH07_MyboleView();
	DECLARE_DYNCREATE(CCH07_MyboleView)

// ����
public:
	CCH07_MyboleDoc* GetDocument() const;

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
	virtual ~CCH07_MyboleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDialog();
};

#ifndef _DEBUG  // CH07_MyboleView.cpp �еĵ��԰汾
inline CCH07_MyboleDoc* CCH07_MyboleView::GetDocument() const
   { return reinterpret_cast<CCH07_MyboleDoc*>(m_pDocument); }
#endif

