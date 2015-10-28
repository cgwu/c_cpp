// CollectionsDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CollectionsDemo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

void TestCollections(){
	_tsetlocale (LC_ALL, _T("chs"));		//解决中文乱码的问题
	// CArray可增长的数组,与 vector相似
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
		_tprintf(_T("数组:%ls\n"), sa[i] );
		//TRACE(sa[i]);
		TRACE(_T("第%d位 = [%ls]\n"), i, sa[i]);		//打印调试信息
	}

	//CList是链表
	CStringList sl;
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(_T("链表idx%d = %d"),i, i+1);
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
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
			TestCollections();
			getchar();
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
