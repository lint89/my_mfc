#include "stdafx.h"
#include "TestBtn.h"


CTestBtn::CTestBtn(void)
{
}


CTestBtn::~CTestBtn(void)
{
}


void CTestBtn::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{

//#5019

	// TODO:  添加您的代码以绘制指定项
	UINT uStyle = DFCS_BUTTONPUSH;
	//ASSERT(LPDRAWITEMSTRUCT->CtlType == ODT_BUTTON);
}
