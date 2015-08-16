
// CH05_TextView.h : CCH05_TextView ��Ľӿ�
//

#pragma once


class CCH05_TextView : public CView
{
protected: // �������л�����
	CCH05_TextView();
	DECLARE_DYNCREATE(CCH05_TextView)

// ����
public:
	CCH05_TextDoc* GetDocument() const;

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
	virtual ~CCH05_TextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // CH05_TextView.cpp �еĵ��԰汾
inline CCH05_TextDoc* CCH05_TextView::GetDocument() const
   { return reinterpret_cast<CCH05_TextDoc*>(m_pDocument); }
#endif

