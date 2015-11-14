
// SquaresView.cpp : CSquaresView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SdiSquares.h"
#endif

#include "SquaresDoc.h"
#include "SquaresView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSquaresView

IMPLEMENT_DYNCREATE(CSquaresView, CView)

BEGIN_MESSAGE_MAP(CSquaresView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSquaresView 构造/析构

CSquaresView::CSquaresView()
{
	// TODO: 在此处添加构造代码

}

CSquaresView::~CSquaresView()
{
}

BOOL CSquaresView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSquaresView 绘制

void CSquaresView::OnDraw(CDC* pDC)
{
	CSquaresDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// MM_LOENGLISH：每个逻辑单位转换为0.01英寸，X正方向向右，Y正方向向上。
	pDC->SetMapMode(MM_LOENGLISH);

	// TODO: 在此处为本机数据添加绘制代码
	//画16个方块
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			COLORREF color = pDoc->GetSquare(i,j);
			CBrush brush(color);
			int x1 = j * 100 + 50;
			int y1 = i * -100 - 50;
			int x2 = x1 + 100;
			int y2 = y1 - 100;
			CRect rect(x1, y1, x2, y2);
			pDC->FillRect(rect, &brush);
		}
	}
	// 画竖边框
	for (int x = 50; x <= 450; x += 100)
	{
		pDC->MoveTo(x, -50);
		pDC->LineTo(x, -450);
	}
	// 画横边框
	for (int y = -50; y >= -450; y -= 100)
	{
		pDC->MoveTo(50, y);
		pDC->LineTo(450, y);
	}
}


// CSquaresView 打印

BOOL CSquaresView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSquaresView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSquaresView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSquaresView 诊断

#ifdef _DEBUG
void CSquaresView::AssertValid() const
{
	CView::AssertValid();
}

void CSquaresView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSquaresDoc* CSquaresView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSquaresDoc)));
	return (CSquaresDoc*)m_pDocument;
}
#endif //_DEBUG


// CSquaresView 消息处理程序


void CSquaresView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CClientDC dc(this);
	dc.SetMapMode(MM_LOENGLISH);
	CPoint pos = point;
	dc.DPtoLP(&pos);
	if(pos.x >= 50 && pos.x <= 450 
		&& pos.y <= -50 && pos.y >= -450){
		int i = (-pos.y - 50) / 100;
		int j = (pos.x - 50) / 100;
		TRACE("i=%d,j=%d\n",i,j);
		CSquaresDoc * pDoc = GetDocument();
		COLORREF clrCurrentColor = pDoc->GetCurrentColor();
		pDoc->SetSquare(i,j, clrCurrentColor);
		TRACE("current color: %x\n", clrCurrentColor);
	}
}
