
// ChildView.cpp : CChildView 类的实现
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
	m_bMouseOver = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_NCHITTEST()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView 消息处理程序

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
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	dc.TextOutW(0,0,CString(_T("Hello中国")));
	// 不要为绘制消息而调用 CWnd::OnPaint()
}



LRESULT CChildView::OnNcHitTest(CPoint point)
{
	//TRACE(_T("CChildView :: WM_NCHITTEST(%d,%d)\n"),point.x, point.y);
	UINT nHitTest = CWnd::OnNcHitTest(point);
	/*
	if(nHitTest == HTCLIENT){
		nHitTest = HTCAPTION;
	}
	*/
	return nHitTest;
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	//TRACE(_T("ChildView :: OnMouseMove (%d,%d)\n"), point.x, point.y);
	if(!m_bMouseOver){
		TRACE(_T("Mouse enter\n"));
		m_bMouseOver = TRUE;
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_HOVER | TME_LEAVE;
		tme.hwndTrack = m_hWnd;
		tme.dwHoverTime = HOVER_DEFAULT;
		::TrackMouseEvent(&tme);
	}
	//CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnMouseHover(UINT nFlags, CPoint point)
{
	TRACE(_T("ChildView :: OnMouseHover (%d,%d)\n"), point.x, point.y);
	TRACKMOUSEEVENT tme;
	tme.cbSize = sizeof(tme);
	tme.dwFlags = TME_HOVER | TME_LEAVE;
	tme.hwndTrack = m_hWnd;
	tme.dwHoverTime = HOVER_DEFAULT;
	::TrackMouseEvent(&tme);
	
	//CWnd::OnMouseHover(nFlags, point);
}


void CChildView::OnMouseLeave()
{
	TRACE(_T("ChildView :: OnMouseLeave\n"));
	m_bMouseOver = FALSE;
	CWnd::OnMouseLeave();
}


// SetCapture, ReleaseCapture 的意义在于：当鼠标在窗体外ButtonUp时，
// 当前窗体仍可接收到 WM_LBUTTONUP消息，只是坐标超出窗体范围。
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_ptFrom = point;
	SetCapture();
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(GetCapture() == this) ::ReleaseCapture();
	CClientDC dc(this);
	dc.MoveTo(m_ptFrom);
	dc.LineTo(point);
}
