
// CHtmlViewDemoView.cpp : CCHtmlViewDemoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CCHtmlViewDemoView ����/����

CCHtmlViewDemoView::CCHtmlViewDemoView()
{
	// TODO: �ڴ˴���ӹ������

}

CCHtmlViewDemoView::~CCHtmlViewDemoView()
{
}

BOOL CCHtmlViewDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CCHtmlViewDemoView ���

#ifdef _DEBUG
void CCHtmlViewDemoView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CCHtmlViewDemoView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CCHtmlViewDemoDoc* CCHtmlViewDemoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHtmlViewDemoDoc)));
	return (CCHtmlViewDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CCHtmlViewDemoView ��Ϣ�������
