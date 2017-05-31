#include <iostream>
using namespace std;

int main(int argc, char* argv [])
{
	string line;
	while(getline(cin,line)) {
		cout << line << endl;
		string::size_type size = line.size();
		cout << "串大小：" << size<< endl;
	}
	return 0;
}
