
// CViewDemoView.cpp : CCViewDemoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CCViewDemoView ����/����

CCViewDemoView::CCViewDemoView()
{
	// TODO: �ڴ˴���ӹ������

}

CCViewDemoView::~CCViewDemoView()
{
}

BOOL CCViewDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
	return CScrollView::PreCreateWindow(cs);
}

// CCViewDemoView ����

void CCViewDemoView::OnDraw(CDC* /*pDC*/)
{
	CCViewDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CCViewDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CCViewDemoView ��ӡ

BOOL CCViewDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCViewDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCViewDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCViewDemoView ���

#ifdef _DEBUG
void CCViewDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCViewDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCViewDemoDoc* CCViewDemoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCViewDemoDoc)));
	return (CCViewDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CCViewDemoView ��Ϣ�������


void CCViewDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPoint pos = point;
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&pos);

	CSize size = GetTotalSize();		//��ȡview���߼���Ⱥ͸߶�
	if(::abs(pos.y) < (size.cy / 2)){
		MessageBox(_T("���λ����ScrollView���ϰ벿��"));
	}
	else{
		MessageBox(_T("���λ����ScrollView���°벿��"));
	}
	//CScrollView::OnLButtonDown(nFlags, point);
}


void CCViewDemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPoint pos = GetScrollPosition();	//���¡����ҹ�����ƫ��
	CString str;
	str.Format(_T("cx = %d, cy=%d"), pos.x, pos.y);
	MessageBox(str);
	//CScrollView::OnRButtonDown(nFlags, point);
}
