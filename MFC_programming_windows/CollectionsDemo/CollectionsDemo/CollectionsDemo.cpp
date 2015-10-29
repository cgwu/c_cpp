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

UINT AFXAPI HashKey(CString& string){
	LPCTSTR key = (LPCTSTR)string;
	UINT nHash = 0;
	while(*key) nHash = (nHash << 5) + nHash + *key ++;
	return nHash;
}

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
	//CList ����
	CList<CPoint, CPoint&> list;
	//��һ��ģ�����ָ������������(CPoint����)
	//�ڶ�������ָ�������б����б���Ĵ��ͷ�ʽ(ͨ������)
	//CList�а����Զ�������ʱ����Ҫ����==�����
	for (int i = 0; i < 10; i++)
	{
		list.AddTail(CPoint(i * 10, i));
	}
	POSITION posList = list.GetHeadPosition();
	while(posList != NULL){
		CPoint pt = list.GetNext(posList);
		TRACE(_T("x=%d, y=%d\n"),pt.x, pt.y);
	}
	// MFCӳ�������
	CMapStringToString map;
	map[_T("Sun")] = _T("������");
	map[_T("Mon")] = _T("����һ");
	map[_T("Tue")] = _T("���ڶ�");
	map[_T("Wed")] = _T("������");
	map[_T("Thu")] = _T("������");
	map[_T("Fri")] = _T("������");
	map[_T("Sat")] = _T("������");
	CString strDay;
	if(map.Lookup(_T("Fri"), strDay)){
		TRACE(_T("��Ҫ�ҵ���Ϊ:%s\n"), strDay);
	}
	POSITION posMap = map.GetStartPosition();
	while(posMap != NULL){
		CString strKey, strItem;
		map.GetNextAssoc(posMap, strKey, strItem);
		TRACE(_T("��= %s, ֵ= %s\n"), strKey, strItem);
	}
	//�������͵�CMap
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
