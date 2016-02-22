#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	vector<char> v1;
	v1.resize(41);
	strcpy(&v1[0], "Hello中国");
	printf("v1=%s\n", &v1[0]);
	
	string s("12345");
	char buf[20]={0,};
	memcpy(buf, s.data(),s.size());
	printf(buf);
	s += "中国"; 
	cout << endl;
	strcpy(buf,s.c_str());
	printf(buf);
	cout << endl;
	
	cout << s.substr(2,2) << endl;
	/*
	vector<int> vi;
	for(int i=0; i <= 6; ++i){
		vi.push_back(i);
		//vi.push_front(i);
	}
	for(int i=0;i<vi.size();++i)
	{
		cout << vi[i] << " ";
	}
	cout << endl;
	*/
	/*
	copy(vi.begin(), vi.end(), 
		ostream_iterator<int>(cout, " "));
	*/	
	/*
	vector<string> col1;
	
	copy(istream_iterator<string>(cin),		// start of source
		istream_iterator<string>(),			// end of source
		back_inserter(col1));				// desination

	sort(col1.begin(), col1.end());

	unique_copy(col1.begin(), col1.end(),
		ostream_iterator<string>(cout,"\n"));
	*/
	
	//getchar();
	return 0;
}
