
// CH04_Draw.h : CH04_Draw Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCH04_DrawApp:
// �йش����ʵ�֣������ CH04_Draw.cpp
//

class CCH04_DrawApp : public CWinAppEx
{
public:
	CCH04_DrawApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH04_DrawApp theApp;
