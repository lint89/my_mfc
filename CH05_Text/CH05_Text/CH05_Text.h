
// CH05_Text.h : CH05_Text Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCH05_TextApp:
// �йش����ʵ�֣������ CH05_Text.cpp
//

class CCH05_TextApp : public CWinApp
{
public:
	CCH05_TextApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH05_TextApp theApp;
