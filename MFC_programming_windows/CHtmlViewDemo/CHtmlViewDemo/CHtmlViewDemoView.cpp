
// CHtmlViewDemoView.cpp : CCHtmlViewDemoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CHtmlViewDemo.h"
#endif

#include "CHtmlViewDemoDoc.h"
#include "CHtmlViewDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCHtmlViewDemoView

IMPLEMENT_DYNCREATE(CCHtmlViewDemoView, CHtmlView)

BEGIN_MESSAGE_MAP(CCHtmlViewDemoView, CHtmlView)
END_MESSAGE_MAP()

// CCHtmlViewDemoView 构造/析构

CCHtmlViewDemoView::CCHtmlViewDemoView()
{
	// TODO: 在此处添加构造代码

}

CCHtmlViewDemoView::~CCHtmlViewDemoView()
{
}

BOOL CCHtmlViewDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void CCHtmlViewDemoView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	TCHAR szPath[255];
	::GetModuleFileName(NULL,szPath, sizeof(szPath) / sizeof(TCHAR));

	CString path = szPath;
	int nIndex = path.ReverseFind(_T('\\'));
	ASSERT(nIndex != -1);
	path = path.Left(nIndex + 1) + _T("index.html");
	Navigate2(path);

	//Navigate2(_T("http://www.baidu.com/"),NULL,NULL);
}


// CCHtmlViewDemoView 诊断

#ifdef _DEBUG
void CCHtmlViewDemoView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CCHtmlViewDemoView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CCHtmlViewDemoDoc* CCHtmlViewDemoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHtmlViewDemoDoc)));
	return (CCHtmlViewDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CCHtmlViewDemoView 消息处理程序
