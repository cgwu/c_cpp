
// CViewDemoView.cpp : CCViewDemoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CViewDemo.h"
#endif

#include "CViewDemoDoc.h"
#include "CViewDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCViewDemoView

IMPLEMENT_DYNCREATE(CCViewDemoView, CScrollView)

BEGIN_MESSAGE_MAP(CCViewDemoView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCViewDemoView 构造/析构

CCViewDemoView::CCViewDemoView()
{
	// TODO: 在此处添加构造代码

}

CCViewDemoView::~CCViewDemoView()
{
}

BOOL CCViewDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	
	return CScrollView::PreCreateWindow(cs);
}

// CCViewDemoView 绘制

void CCViewDemoView::OnDraw(CDC* /*pDC*/)
{
	CCViewDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CCViewDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CCViewDemoView 打印

BOOL CCViewDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCViewDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCViewDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCViewDemoView 诊断

#ifdef _DEBUG
void CCViewDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCViewDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCViewDemoDoc* CCViewDemoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCViewDemoDoc)));
	return (CCViewDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CCViewDemoView 消息处理程序
