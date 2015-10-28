
// CHtmlViewDemoView.h : CCHtmlViewDemoView 类的接口
//

#pragma once


class CCHtmlViewDemoView : public CHtmlView
{
protected: // 仅从序列化创建
	CCHtmlViewDemoView();
	DECLARE_DYNCREATE(CCHtmlViewDemoView)

// 特性
public:
	CCHtmlViewDemoDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CCHtmlViewDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CHtmlViewDemoView.cpp 中的调试版本
inline CCHtmlViewDemoDoc* CCHtmlViewDemoView::GetDocument() const
   { return reinterpret_cast<CCHtmlViewDemoDoc*>(m_pDocument); }
#endif

