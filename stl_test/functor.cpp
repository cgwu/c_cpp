#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class PrintInt{
public:
	void operator() (int elem) const{
		cout << elem << " ";
	}
};

int main(int argc, char *argv[])
{
    PrintInt fp;//函数对象
	fp(110);
	vector<int> vi;
	for(int i=0;i<10;++i){
		vi.push_back(i);
	}
	for_each(vi.begin(),vi.end(),fp);
	cout<<endl;
    return 0;
}
