
// SquaresView.h : CSquaresView ��Ľӿ�
//

#pragma once


class CSquaresView : public CView
{
protected: // �������л�����
	CSquaresView();
	DECLARE_DYNCREATE(CSquaresView)

// ����
public:
	CSquaresDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSquaresView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SquaresView.cpp �еĵ��԰汾
inline CSquaresDoc* CSquaresView::GetDocument() const
   { return reinterpret_cast<CSquaresDoc*>(m_pDocument); }
#endif

