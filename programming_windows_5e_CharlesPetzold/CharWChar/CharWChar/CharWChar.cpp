// CharWChar.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//setlocale(LC_CTYPE, "");
	_tsetlocale (LC_ALL, _T("chs"));		//����������������
	printf("Hello�й�\n");

	TCHAR ch ='a';
	// _T, __T, _TEXT ����һ����(����windows.h��TEXTҲ��һ��)����UNICODE�±�����ΪL##x�� �� L"Hello�й�"
	//TCHAR str[] = TEXT("Hello�й�");
	TCHAR str[] = _T("Hello�й�");
	_tprintf(_T("ch=%c,str=%ls\n"), ch, str);

	getchar();
	return 0;
}

