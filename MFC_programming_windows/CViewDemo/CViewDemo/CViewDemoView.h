
// CViewDemoView.h : CCViewDemoView ��Ľӿ�
//

#pragma once


class CCViewDemoView : public CScrollView
{
protected: // �������л�����
	CCViewDemoView();
	DECLARE_DYNCREATE(CCViewDemoView)

// ����
public:
	CCViewDemoDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CCViewDemoView();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // CViewDemoView.cpp �еĵ��԰汾
inline CCViewDemoDoc* CCViewDemoView::GetDocument() const
   { return reinterpret_cast<CCViewDemoDoc*>(m_pDocument); }
#endif

