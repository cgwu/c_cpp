#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y) //定位到第y行的第x列
{
	HANDLE hOutput;
	COORD loc;
	loc.X = x;
	loc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
} 
int main(){
	//clrscr();
	
	gotoxy(20,40);
	printf("Hello 中国");
	gotoxy(0,0);
	printf("start...");
	
	return 0;
}