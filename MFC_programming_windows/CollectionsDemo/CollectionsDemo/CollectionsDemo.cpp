// CollectionsDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CollectionsDemo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

void TestCollections(){
	_tsetlocale (LC_ALL, _T("chs"));		//����������������
	// CArray������������,�� vector����
	CUIntArray array;
	array.SetSize(10);
	for(int i=0;i<10;++i){
		array[i] = i+1;
	}
	for(int i=0;i<10;++i){
		_tprintf(_T("array[%d]=%u\n"),i,array[i]);
	}
	
	CStringArray sa;
	sa.SetSize(10);
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(_T("idx%d = %d"),i, i+1);
		sa[i] = str;
	}
	for (int i = 0; i < 10; i++)
	{
		//wcout << sa[i].GetString() << endl;
		_tprintf(_T("����:%ls\n"), sa[i] );
		//TRACE(sa[i]);
		TRACE(_T("��%dλ = [%ls]\n"), i, sa[i]);		//��ӡ������Ϣ
	}

	//CList������
	CStringList sl;
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(_T("����idx%d = %d"),i, i+1);
		sl.AddTail(str);
	}
	_tprintf(_T("-------------------\n"));
	POSITION pos = sl.GetHeadPosition();
	while (pos != NULL)
	{
		CString str = sl.GetNext(pos);
		_tprintf(_T("%ls\n"), str.GetBuffer() );
	}
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
			TestCollections();
			getchar();
		}
	}
	else
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
