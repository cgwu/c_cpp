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
	Create(NULL,_T("你好 Application!"), (WS_OVERLAPPEDWINDOW /* | WS_VSCROLL | WS_HSCROLL */ ) 
		 /* & (~WS_MAXIMIZEBOX) & (~WS_SYSMENU) & (~WS_THICKFRAME)  & (~WS_BORDER) */ );
}

void CMainWindow::OnPaint() {
	OutputDebugString(_T("CMainWindow::OnPaint called.\n"));
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(_T("你好,MFC!"),-1,&rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	//ModifyStyle(WS_CAPTION,0);		// 去掉标题
	//ModifyStyle(WS_THICKFRAME,0);		// 去掉边框
	
	//SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE,0);		//最大化

	OutputDebugString(_T("CMainWindow::OnCreate called.\n"));
	return 0;
}

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	CRect rect;
	GetClientRect(&rect);

	CClientDC dc(this);
	//CClientDC dc(NULL);		//桌面上的DC
	//CWindowDC dc(this);		//包含非客户区
	//dc.SetBkMode(TRANSPARENT);
	//dc.SetROP2(R2_NOT);
	//dc.SetROP2(R2_BLACK);
	/*
	dc.MoveTo(rect.left, rect.top);
	dc.LineTo(rect.right, rect.bottom);
	dc.MoveTo(rect.right, rect.top);
	dc.LineTo(rect.left, rect.bottom);

	dc.Rectangle(10,10, 200,100);
	dc.SetMapMode(MM_LOMETRIC);
	dc.Ellipse(0,0,500,-500);
	*/

	/***************************** 映射模式测试  *********************************/
	//dc.SetMapMode(MM_ISOTROPIC);
	dc.SetMapMode(MM_ANISOTROPIC);
	/*
	dc.SetWindowExt(500,500);		//逻辑坐标范围, Y坐标向下为正
	dc.SetViewportExt(rect.Width(), rect.Height());		//设备坐标范围
	dc.Ellipse(0,0,500,500);
	*/
	dc.SetWindowExt(500, -500);		//逻辑坐标范围, Y坐标向下为负
	dc.SetViewportExt(rect.Width(), rect.Height());		//设备坐标范围
	/*
	用SetViewportOrg将视口原点移至(x,y)等价于通知Windows把逻辑点(0,0)映射成设备点(x,y)。
	用SetWindowOrg将窗口原点移至(x,y)则恰恰相反，它等价于告诉Windows将逻辑点(x,y)映射成设备点(0,0)，
		即显示平面的左上角。
	*/
	dc.SetViewportOrg(rect.Width()/2, rect.Height()/2);	//移动设备坐标原点到中心

	//dc.Ellipse(0, 0, 500, -500);
	/*
	dc.MoveTo(0,0);
	dc.LineTo(250,250);
	//dc.LineTo(245,245);
	*/
	dc.MoveTo(-245,-245);
	dc.LineTo(245,245);

	int cx = dc.GetDeviceCaps(HORZRES);		//屏幕的宽度
	int cy = dc.GetDeviceCaps(VERTRES);
	CString str;
	str.Format(_T("宽:%d,高:%d"),cx,cy);
	SetWindowText(str);
}
