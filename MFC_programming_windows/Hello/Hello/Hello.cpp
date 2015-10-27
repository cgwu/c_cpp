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
	Create(NULL,_T("��� Application!"), (WS_OVERLAPPEDWINDOW /* | WS_VSCROLL | WS_HSCROLL */ ) 
		 /* & (~WS_MAXIMIZEBOX) & (~WS_SYSMENU) & (~WS_THICKFRAME)  & (~WS_BORDER) */ );
}

void CMainWindow::OnPaint() {
	OutputDebugString(_T("CMainWindow::OnPaint called.\n"));
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(_T("���,MFC!"),-1,&rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	//ModifyStyle(WS_CAPTION,0);		// ȥ������
	//ModifyStyle(WS_THICKFRAME,0);		// ȥ���߿�
	
	//SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE,0);		//���

	OutputDebugString(_T("CMainWindow::OnCreate called.\n"));
	return 0;
}

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	CRect rect;
	GetClientRect(&rect);

	CClientDC dc(this);
	//CClientDC dc(NULL);		//�����ϵ�DC
	//CWindowDC dc(this);		//�����ǿͻ���
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

	/***************************** ӳ��ģʽ����  *********************************/
	//dc.SetMapMode(MM_ISOTROPIC);
	dc.SetMapMode(MM_ANISOTROPIC);
	/*
	dc.SetWindowExt(500,500);		//�߼����귶Χ, Y��������Ϊ��
	dc.SetViewportExt(rect.Width(), rect.Height());		//�豸���귶Χ
	dc.Ellipse(0,0,500,500);
	*/
	dc.SetWindowExt(500, -500);		//�߼����귶Χ, Y��������Ϊ��
	dc.SetViewportExt(rect.Width(), rect.Height());		//�豸���귶Χ
	/*
	��SetViewportOrg���ӿ�ԭ������(x,y)�ȼ���֪ͨWindows���߼���(0,0)ӳ����豸��(x,y)��
	��SetWindowOrg������ԭ������(x,y)��ǡǡ�෴�����ȼ��ڸ���Windows���߼���(x,y)ӳ����豸��(0,0)��
		����ʾƽ������Ͻǡ�
	*/
	dc.SetViewportOrg(rect.Width()/2, rect.Height()/2);	//�ƶ��豸����ԭ�㵽����

	//dc.Ellipse(0, 0, 500, -500);
	/*
	dc.MoveTo(0,0);
	dc.LineTo(250,250);
	//dc.LineTo(245,245);
	*/
	dc.MoveTo(-245,-245);
	dc.LineTo(245,245);

	int cx = dc.GetDeviceCaps(HORZRES);		//��Ļ�Ŀ��
	int cy = dc.GetDeviceCaps(VERTRES);
	CString str;
	str.Format(_T("��:%d,��:%d"),cx,cy);
	SetWindowText(str);
}
