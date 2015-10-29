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

UINT AFXAPI HashKey(CString& string){
	LPCTSTR key = (LPCTSTR)string;
	UINT nHash = 0;
	while(*key) nHash = (nHash << 5) + nHash + *key ++;
	return nHash;
}

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
	//CList 范型
	CList<CPoint, CPoint&> list;
	//第一个模板参数指定了数据类型(CPoint对象)
	//第二个参数指出参数列表中列表项的传送方式(通过引用)
	//CList中包含自定义类型时，需要重载==运算符
	for (int i = 0; i < 10; i++)
	{
		list.AddTail(CPoint(i * 10, i));
	}
	POSITION posList = list.GetHeadPosition();
	while(posList != NULL){
		CPoint pt = list.GetNext(posList);
		TRACE(_T("x=%d, y=%d\n"),pt.x, pt.y);
	}
	// MFC映射表类型
	CMapStringToString map;
	map[_T("Sun")] = _T("星期天");
	map[_T("Mon")] = _T("星期一");
	map[_T("Tue")] = _T("星期二");
	map[_T("Wed")] = _T("星期三");
	map[_T("Thu")] = _T("星期四");
	map[_T("Fri")] = _T("星期五");
	map[_T("Sat")] = _T("星期六");
	CString strDay;
	if(map.Lookup(_T("Fri"), strDay)){
		TRACE(_T("你要找的天为:%s\n"), strDay);
	}
	POSITION posMap = map.GetStartPosition();
	while(posMap != NULL){
		CString strKey, strItem;
		map.GetNextAssoc(posMap, strKey, strItem);
		TRACE(_T("键= %s, 值= %s\n"), strKey, strItem);
	}
	//任意类型的CMap
	CMap<CString, LPCTSTR, CPoint,CPoint&> mapSP;
	mapSP[CString(_T("p1"))] = CPoint(1,2);
	mapSP[CString(_T("p2"))] = CPoint(11,22);
	CPoint p2;
	if(mapSP.Lookup(_T("p2"),p2)){
		TRACE(_T("p2 = (%d, %d)"), p2.x, p2.y);
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
