
// MouseKeyboard.h : MouseKeyboard Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMouseKeyboardApp:
// �йش����ʵ�֣������ MouseKeyboard.cpp
//

class CMouseKeyboardApp : public CWinApp
{
public:
	CMouseKeyboardApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMouseKeyboardApp theApp;
