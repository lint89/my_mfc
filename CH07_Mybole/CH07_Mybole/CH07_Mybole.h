
// CH07_Mybole.h : CH07_Mybole 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CCH07_MyboleApp:
// 有关此类的实现，请参阅 CH07_Mybole.cpp
//

class CCH07_MyboleApp : public CWinAppEx
{
public:
	CCH07_MyboleApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH07_MyboleApp theApp;
