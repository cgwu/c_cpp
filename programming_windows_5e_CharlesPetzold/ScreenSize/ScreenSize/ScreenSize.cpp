// ScreenSize.cpp : 定义应用程序的入口点。
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
   size_t sizeOfBuffer,		//缓冲区字符个数
   size_t count,			//最大长度,去掉末尾的0
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
	MessageBoxPrintf(_T("提示"), _T("i = %d, str = %s"), 1024, _T("Hello中国"));
	return 0;
}


