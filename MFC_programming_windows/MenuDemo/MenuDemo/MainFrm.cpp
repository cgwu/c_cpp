
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MenuDemo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_FILE_OPEN_NEW, &CMainFrame::OnFileOpenNew)
	ON_COMMAND(ID_FILE_EXIT_NEW, &CMainFrame::OnFileExitNew)
	/*
	ON_COMMAND(ID_COLOR_RED, &CMainFrame::OnColor)
	ON_COMMAND(ID_COLOR_GREEN, &CMainFrame::OnColor)
	ON_COMMAND(ID_COLOR_BLUE, &CMainFrame::OnColor)
	*/
	ON_COMMAND_RANGE(ID_COLOR_RED, ID_COLOR_BLUE, &CMainFrame::OnColorRange)
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// ����һ����ͼ��ռ�ÿ�ܵĹ�����
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("δ�ܴ�����ͼ����\n");
		return -1;
	}
	// �޸�ϵͳ�˵�
	CMenu *pSystemMenu = GetSystemMenu(FALSE);
	pSystemMenu->AppendMenuW(MF_SEPARATOR);
	pSystemMenu->AppendMenuW(MF_STRING, ID_APP_ABOUT,_T("������(&A)"));
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ������ǰ�Ƶ���ͼ����
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// ����ͼ��һ�γ��Ը�����
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// ����ִ��Ĭ�ϴ���
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



void CMainFrame::OnFileOpenNew()
{
	UINT nID = (UINT)LOWORD(GetCurrentMessage()->wParam);
	TRACE(_T("nID=%u\n"), nID);
	MessageBox(_T("���ļ�������"));
}


void CMainFrame::OnFileExitNew()
{
	// ���͹ر���Ϣ
	PostMessage(WM_CLOSE,0,0);
}


void CMainFrame::OnColor()
{
	UINT nID = (UINT)LOWORD(GetCurrentMessage()->wParam);
	m_nCurrentColor = nID - ID_COLOR_RED;
	CString str;
	str.Format(_T("color=%d"),m_nCurrentColor);
	MessageBox(str);
}

void CMainFrame::OnColorRange(UINT nID)
{
	CMenu *pMenu = GetMenu();
	pMenu->CheckMenuItem(m_nCurrentColor + ID_COLOR_RED, MF_UNCHECKED);
	m_nCurrentColor = nID - ID_COLOR_RED;	//�µ�
	pMenu->CheckMenuItem(nID, MF_CHECKED);

	CString str;
	str.Format(_T("color=%d"),m_nCurrentColor);
	MessageBox(str);
}


void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if((nID & 0xfff0) == ID_APP_ABOUT){
		SendMessage(WM_COMMAND,ID_APP_ABOUT,0);
		return;
	}
	CFrameWnd::OnSysCommand(nID, lParam);
}
