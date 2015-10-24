// CharWChar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//setlocale(LC_CTYPE, "");
	_tsetlocale (LC_ALL, _T("chs"));		//解决中文乱码的问题
	printf("Hello中国\n");

	TCHAR ch ='a';
	TCHAR str[] = _T("Hello中国");		// _T, __T, _TEXT 都是一样的，在UNICODE下被定义为L##x， 如 L"Hello中国"
	_tprintf(_T("ch=%c,str=%ls\n"), ch, str);

	getchar();
	return 0;
}

