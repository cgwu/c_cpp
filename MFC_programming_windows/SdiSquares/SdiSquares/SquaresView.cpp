
// SquaresView.cpp : CSquaresView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSquaresView ����/����

CSquaresView::CSquaresView()
{
	// TODO: �ڴ˴���ӹ������

}

CSquaresView::~CSquaresView()
{
}

BOOL CSquaresView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSquaresView ����

void CSquaresView::OnDraw(CDC* pDC)
{
	CSquaresDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// MM_LOENGLISH��ÿ���߼���λת��Ϊ0.01Ӣ�磬X���������ң�Y���������ϡ�
	pDC->SetMapMode(MM_LOENGLISH);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//��16������
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
	// �����߿�
	for (int x = 50; x <= 450; x += 100)
	{
		pDC->MoveTo(x, -50);
		pDC->LineTo(x, -450);
	}
	// ����߿�
	for (int y = -50; y >= -450; y -= 100)
	{
		pDC->MoveTo(50, y);
		pDC->LineTo(450, y);
	}
}


// CSquaresView ��ӡ

BOOL CSquaresView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSquaresView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSquaresView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSquaresView ���

#ifdef _DEBUG
void CSquaresView::AssertValid() const
{
	CView::AssertValid();
}

void CSquaresView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSquaresDoc* CSquaresView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSquaresDoc)));
	return (CSquaresDoc*)m_pDocument;
}
#endif //_DEBUG


// CSquaresView ��Ϣ�������


void CSquaresView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
