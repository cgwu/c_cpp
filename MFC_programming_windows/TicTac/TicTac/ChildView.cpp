
// ChildView.cpp : CChildView 类的实现
//

#include "stdafx.h"
#include "TicTac.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_nNextChar = EX;
	::ZeroMemory(m_nGameGrid, 9 * sizeof(int));
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

const CRect CChildView::m_rcSquares[9] = {
	CRect(16,16,112,112),
	CRect(128,16,224,112),
	CRect(240,16,336,112),

	CRect(16,128,112,224),
	CRect(128,128,224,224),
	CRect(240,128,336,224),

	CRect(16,240,112,336),
	CRect(128,240,224,336),
	CRect(240,240,336,336)
};

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
	DrawBorder(&dc);
	// 不要为绘制消息而调用 CWnd::OnPaint()
}


void CChildView:: DrawBorder(CDC *pDC){
	CPen pen(PS_SOLID, 16, RGB(0,0,0));
	CPen *pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(120,16);
	pDC->LineTo(120,336);

	pDC->MoveTo(232, 16);
	pDC->LineTo(232, 336);

	pDC->MoveTo(16,120);
	pDC->LineTo(336, 120);

	pDC->MoveTo(16,232);
	pDC->LineTo(336, 232);

	// Draw the Xs and Os.
	for (int i = 0; i < 9; i++)
	{
		if(m_nGameGrid[i] == EX)
			DrawX(pDC,i);
		else if(m_nGameGrid[i] == OH)
			DrawO(pDC,i);
	}

	pDC->SelectObject(pOldPen);
}

void CChildView::DrawX(CDC *pDC, int nPos){
	CPen pen(PS_SOLID, 16,RGB(225,0,0));
	CPen *pOldPen = pDC->SelectObject(&pen);

	CRect rect = m_rcSquares[nPos];
	rect.DeflateRect(16,16);
	pDC->MoveTo(rect.left,rect.top);
	pDC->LineTo(rect.right,rect.bottom);
	pDC->MoveTo(rect.left,rect.bottom);
	pDC->LineTo(rect.right,rect.top);

	pDC->SelectObject(pOldPen);
}


void CChildView::DrawO(CDC *pDC, int nPos){
	CPen pen(PS_SOLID, 16,RGB(0,0,255));
	CPen *pOldPen = pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);

	CRect rect = m_rcSquares[nPos];
	rect.DeflateRect(16,16);
	pDC->Ellipse(rect);

	pDC->SelectObject(pOldPen);
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(this->m_nNextChar != EX) return;
	int nPos = GetRectID(point);
	if((nPos == -1) || (m_nGameGrid[nPos] != 0)) return;

	m_nGameGrid[nPos] = EX;
	m_nNextChar = OH;

	CClientDC dc(this);
	DrawX(&dc, nPos);
	CheckForGameOver();
}



void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	if(this->m_nNextChar != OH) return;
	int nPos = GetRectID(point);
	if((nPos == -1) || (m_nGameGrid[nPos] != 0)) return;

	m_nGameGrid[nPos] = OH;
	m_nNextChar = EX;

	CClientDC dc(this);
	DrawO(&dc, nPos);
	CheckForGameOver();
}

int CChildView::GetRectID(CPoint point){
	for (int i = 0; i < 9; i++)
	{
		if(m_rcSquares[i].PtInRect(point)) return i;
	}
	return -1;
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// 点击黑色粗框时重新开始游戏
	CClientDC dc(this);
	if(dc.GetPixel(point) == RGB(0,0,0)) ResetGame();
}

void CChildView::ResetGame(){
	m_nNextChar = EX;
	::ZeroMemory(m_nGameGrid, 9 * sizeof(int));
	Invalidate();
}

BOOL CChildView::IsDraw(){
	for (int i = 0; i < 9; i++)
	{
		if(m_nGameGrid[i] == 0) return FALSE;
	}
	return TRUE;
}

int CChildView :: IsWinner() {
	static int nPattern[8][3] = {
		0,1,2,
		3,4,5,
		6,7,8,
		0,3,6,
		1,4,7,
		2,5,8,
		0,4,8,
		2,4,6
	};
	for (int i = 0; i < 8; i++)
	{
		if( (m_nGameGrid[nPattern[i][0]] == EX) &&
			(m_nGameGrid[nPattern[i][1]] == EX) &&
			(m_nGameGrid[nPattern[i][2]] == EX) )
			return EX;

		if( (m_nGameGrid[nPattern[i][0]] == OH) &&
			(m_nGameGrid[nPattern[i][1]] == OH) &&
			(m_nGameGrid[nPattern[i][2]] == OH) )
			return OH;

	}
	return 0;
}

void CChildView::CheckForGameOver() {
	int nWinner = 0;
	if(nWinner = IsWinner()){
		CString string = (nWinner == EX) ? _T("X wins!") : _T("O wins!");
		MessageBox(string, _T("Game Over"), MB_ICONEXCLAMATION | MB_OK);
		ResetGame();
	}
	else if(IsDraw()){
		MessageBox(_T("It's a draw!"), _T("Game Over"),
			MB_ICONEXCLAMATION | MB_OK);
		ResetGame();
	}
}
