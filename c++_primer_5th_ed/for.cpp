#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv [])
{
	string str("some string中国");
	for(auto ch : str) {
		cout << ch << endl;
	}	
	for(decltype(str.size()) index = 0; index != str.size() /* && !isspace(str[index]) */; ++index) {
		if(!isspace(str[index])) str[index] = toupper(str[index]);
	}
	for(auto ch : str) {
		cout << ch << endl;
	}	
	cout << str << endl;
	cout << "done" << endl;
	return 0;
}
