// two hellos
void shellofirst();
void shellosecond();

/*
compile dll and lib:
gcc -shared shellofirst.c shellosecond.c -o hello.dll
dlltool --dllname hello.dll --output-def hello.def --output-lib hello.dll.a

compile exe:
gcc stwohellos.c hello.dll -o stwohellos.exe
*/
int main()
{
	shellofirst();
	shellosecond();
	return 0;
}