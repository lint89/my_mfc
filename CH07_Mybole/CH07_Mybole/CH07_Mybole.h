
// CH07_Mybole.h : CH07_Mybole Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCH07_MyboleApp:
// �йش����ʵ�֣������ CH07_Mybole.cpp
//

class CCH07_MyboleApp : public CWinAppEx
{
public:
	CCH07_MyboleApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH07_MyboleApp theApp;
