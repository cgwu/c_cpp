
// DialogDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDialogDemoApp:
// �йش����ʵ�֣������ DialogDemo.cpp
//

class CDialogDemoApp : public CWinApp
{
public:
	CDialogDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDialogDemoApp theApp;