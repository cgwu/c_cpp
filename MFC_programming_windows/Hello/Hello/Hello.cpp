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
	ON_WM_LBUTTONDOWN()
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

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point){
	CRect rect;
	GetClientRect(&rect);

	CClientDC dc(this);
	//CClientDC dc(NULL);		//桌面上的DC
	//CWindowDC dc(this);		//包含非客户区
	//dc.SetBkMode(TRANSPARENT);
	//dc.SetROP2(R2_NOT);
	//dc.SetROP2(R2_BLACK);

	dc.MoveTo(rect.left, rect.top);
	dc.LineTo(rect.right, rect.bottom);
	dc.MoveTo(rect.right, rect.top);
	dc.LineTo(rect.left, rect.bottom);

	dc.Rectangle(10,10, 200,100);
	dc.SetMapMode(MM_LOMETRIC);
	dc.Ellipse(0,0,500,-500);
}
