
// TicTac.h : TicTac Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTicTacApp:
// �йش����ʵ�֣������ TicTac.cpp
//

class CTicTacApp : public CWinApp
{
public:
	CTicTacApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTicTacApp theApp;
