#include "Hello.h"

CMyApp myApp;

// CMyApp member functions
BOOL CMyApp::InitInstance(){
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// CMainWindow message map and member functions
BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()

CMainWindow::CMainWindow(){
	Create(NULL,_T("你好 Application!"), (WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) 
		 /* & (~WS_MAXIMIZEBOX) & (~WS_SYSMENU) & (~WS_THICKFRAME)  & (~WS_BORDER) */ );
}

void CMainWindow::OnPaint(){
	OutputDebugString(_T("CMainWindow::OnPaint called.\n"));
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(_T("你好,MFC!"),-1,&rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct){
	//ModifyStyle(WS_CAPTION,0);		// 去掉标题
	//ModifyStyle(WS_THICKFRAME,0);		// 去掉边框
	
	//SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE,0);		//最大化

	OutputDebugString(_T("CMainWindow::OnCreate called.\n"));
	return 0;
}
