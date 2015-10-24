// ScreenSize.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int CDECL MessageBoxPrintf(TCHAR * szCaption, TCHAR * szFormat,...)
{
	TCHAR szBuffer[10];
	va_list pArgList;
	va_start(pArgList, szFormat);
	//https://msdn.microsoft.com/zh-cn/magazine/d3xd30zz%28de-de%29.aspx
/*int _vsnwprintf_s(
   wchar_t *buffer,
   size_t sizeOfBuffer,		//�������ַ�����
   size_t count,			//��󳤶�,ȥ��ĩβ��0
   const wchar_t *format,
   va_list argptr 
);*/
	//_vsntprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR),szFormat, pArgList);
	_vsntprintf_s(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), sizeof(szBuffer) / sizeof(TCHAR) - 1, szFormat, pArgList);
	va_end(pArgList);
	return MessageBox(NULL,szBuffer,szCaption,0);
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	MessageBoxPrintf(_T("��ʾ"), _T("i = %d, str = %s"), 1024, _T("Hello�й�"));
	return 0;
}


