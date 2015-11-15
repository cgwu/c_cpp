
// SquaresDoc.cpp : CSquaresDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	ON_COMMAND(ID_COLOR_BLUE, &CSquaresDoc::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CSquaresDoc::OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_CYAN, &CSquaresDoc::OnColorCyan)
	ON_UPDATE_COMMAND_UI(ID_COLOR_CYAN, &CSquaresDoc::OnUpdateColorCyan)
	ON_COMMAND(ID_COLOR_GREEN, &CSquaresDoc::OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CSquaresDoc::OnUpdateColorGreen)
	ON_COMMAND(ID_COLOR_RED, &CSquaresDoc::OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CSquaresDoc::OnUpdateColorRed)
	ON_COMMAND(ID_COLOR_WHITE, &CSquaresDoc::OnColorWhite)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE, &CSquaresDoc::OnUpdateColorWhite)
	ON_COMMAND(ID_COLOR_YELLOW, &CSquaresDoc::OnColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW, &CSquaresDoc::OnUpdateColorYellow)
END_MESSAGE_MAP()


// CSquaresDoc 构造/析构

CSquaresDoc::CSquaresDoc()
{
	// TODO: 在此添加一次性构造代码

}

CSquaresDoc::~CSquaresDoc()
{
}

BOOL CSquaresDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
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




// CSquaresDoc 序列化

void CSquaresDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ar<<m_clrGrid[i][j];
			}
		}
		ar<<m_clrCurrentColor;
	}
	else
	{
		// TODO: 在此添加加载代码
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ar >> m_clrGrid[i][j];
			}
		}
		ar >> m_clrCurrentColor;
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CSquaresDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CSquaresDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CSquaresDoc 诊断

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


// CSquaresDoc 命令


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


void CSquaresDoc::OnColorBlue()
{
	// TODO: 在此添加命令处理程序代码
	m_clrCurrentColor = RGB(0,0,255);
}


void CSquaresDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0,0,255));
}


void CSquaresDoc::OnColorCyan()
{
	// TODO: 在此添加命令处理程序代码
	m_clrCurrentColor = RGB(0,255,255);
}


void CSquaresDoc::OnUpdateColorCyan(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0,255,255));
}


void CSquaresDoc::OnColorGreen()
{
	// TODO: 在此添加命令处理程序代码
	m_clrCurrentColor = RGB(0,255,0);
}


void CSquaresDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0,255,0));
}


void CSquaresDoc::OnColorRed()
{
	// TODO: 在此添加命令处理程序代码
	m_clrCurrentColor = RGB(255,0,0);
}


void CSquaresDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255,0,0));
}


void CSquaresDoc::OnColorWhite()
{
	// TODO: 在此添加命令处理程序代码
	m_clrCurrentColor = RGB(255,255,255);
}


void CSquaresDoc::OnUpdateColorWhite(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255,255,255));
}


void CSquaresDoc::OnColorYellow()
{
	// TODO: 在此添加命令处理程序代码
	m_clrCurrentColor = RGB(255,255,0);
}


void CSquaresDoc::OnUpdateColorYellow(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255,255,0));
}
