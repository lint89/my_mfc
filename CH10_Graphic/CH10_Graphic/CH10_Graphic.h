
// CH10_Graphic.h : CH10_Graphic Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCH10_GraphicApp:
// �йش����ʵ�֣������ CH10_Graphic.cpp
//

class CCH10_GraphicApp : public CWinAppEx
{
public:
	CCH10_GraphicApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH10_GraphicApp theApp;
