
// CHtmlViewDemo.h : CHtmlViewDemo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCHtmlViewDemoApp:
// �йش����ʵ�֣������ CHtmlViewDemo.cpp
//

class CCHtmlViewDemoApp : public CWinApp
{
public:
	CCHtmlViewDemoApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCHtmlViewDemoApp theApp;
