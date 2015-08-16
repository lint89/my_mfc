#pragma once
#include "afxwin.h"
class CTestBtn :
	public CButton
{
public:
	CTestBtn(void);
	~CTestBtn(void);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};

