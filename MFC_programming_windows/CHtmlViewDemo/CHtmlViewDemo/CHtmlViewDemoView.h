
// CHtmlViewDemoView.h : CCHtmlViewDemoView ��Ľӿ�
//

#pragma once


class CCHtmlViewDemoView : public CHtmlView
{
protected: // �������л�����
	CCHtmlViewDemoView();
	DECLARE_DYNCREATE(CCHtmlViewDemoView)

// ����
public:
	CCHtmlViewDemoDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CCHtmlViewDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CHtmlViewDemoView.cpp �еĵ��԰汾
inline CCHtmlViewDemoDoc* CCHtmlViewDemoView::GetDocument() const
   { return reinterpret_cast<CCHtmlViewDemoDoc*>(m_pDocument); }
#endif

