
// SquaresDoc.cpp : CSquaresDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SdiSquares.h"
#endif

#include "SquaresDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSquaresDoc

IMPLEMENT_DYNCREATE(CSquaresDoc, CDocument)

BEGIN_MESSAGE_MAP(CSquaresDoc, CDocument)
END_MESSAGE_MAP()


// CSquaresDoc ����/����

CSquaresDoc::CSquaresDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CSquaresDoc::~CSquaresDoc()
{
}

BOOL CSquaresDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_clrGrid[i][j] = RGB(255,255,255);
		}
	}
	m_clrCurrentColor = RGB(255,0,0);
	return TRUE;
}




// CSquaresDoc ���л�

void CSquaresDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CSquaresDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CSquaresDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CSquaresDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSquaresDoc ���

#ifdef _DEBUG
void CSquaresDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSquaresDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSquaresDoc ����


void CSquaresDoc::SetSquare(int i, int j, COLORREF color)
{
	ASSERT( i >= 0 && i <= 3 && j >= 0 && j <= 3 );
	this->m_clrGrid[i][j] = color;
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}


COLORREF CSquaresDoc::GetSquare(int i, int j)
{
	ASSERT( i >= 0 && i <= 3 && j >= 0 && j <= 3 );
	return m_clrGrid[i][j];
}


COLORREF CSquaresDoc::GetCurrentColor(void)
{
	return m_clrCurrentColor;
}
