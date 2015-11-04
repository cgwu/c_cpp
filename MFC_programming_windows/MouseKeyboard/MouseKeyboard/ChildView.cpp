
// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
#include "MouseKeyboard.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()



// CChildView ��Ϣ�������

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	
	// TODO: �ڴ˴������Ϣ����������
	dc.TextOutW(0,0,CString(_T("Hello�й�")));
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
}



LRESULT CChildView::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACE(_T("CChildView :: WM_NCHITTEST(%d,%d)\n"),point.x, point.y);
	UINT nHitTest = CWnd::OnNcHitTest(point);
	if(nHitTest == HTCLIENT){
		nHitTest = HTCAPTION;
	}
	return nHitTest;
}
