
// CViewDemo.h : CViewDemo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCViewDemoApp:
// �йش����ʵ�֣������ CViewDemo.cpp
//

class CCViewDemoApp : public CWinApp
{
public:
	CCViewDemoApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCViewDemoApp theApp;
