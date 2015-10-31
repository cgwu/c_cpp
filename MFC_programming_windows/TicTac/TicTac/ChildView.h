
// ChildView.h : CChildView 类的接口
//


#pragma once


// CChildView 窗口

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

// 构造
public:
	CChildView();

// 特性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

