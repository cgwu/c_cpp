
// ChildView.h : CChildView ��Ľӿ�
//


#pragma once


// CChildView ����

class CChildView : public CWnd
{
protected:
	static const CRect m_rcSquares[9];
	int m_nGameGrid[9];
	int m_nNextChar;
	int GetRectID(CPoint point);
	void DrawBorder(CDC * pDC);
	void DrawX(CDC *pDC, int nPos);
	void DrawO(CDC *pDC, int nPos);
	void ResetGame();
	void CheckForGameOver();
	int IsWinner();
	BOOL IsDraw();

// ����
public:
	CChildView();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

