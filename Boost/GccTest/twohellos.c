// two hellos
void hellofirst(void);
void hellosecond();

/*
��1��
gcc twohellos.c libhello.a -o twohellos.exe
��2��
gcc twohellos.c -L"./" -lhello -o twohellos2.exe

*/
int main()
{
	hellofirst();
	hellosecond();
	return 0;
}