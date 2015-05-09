#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool is_prime(int num){
	num = abs(num);
	if(num == 0 || num == 1 ) return true;
	int divisor = num / 2;
	for(;num % divisor !=0; --divisor);
	return divisor == 1;
}

int main(int argc, char *argv[])
{
	bool isP = is_prime(-5);
	cout << boolalpha << isP << endl;
	cout << noboolalpha << false << endl;

	vector<int> v;
	
	for(int i=20;i<40;++i){
		v.push_back(i);
	}
	
	//v.push_back(4);
	//v.push_back(6);
	vector<int>::iterator pos = find_if(v.begin(), v.end(), is_prime);
	if(pos != v.end()){
		cout << *pos << " is prime." << endl;
	}
	else{
		cout << "no prime found." << endl;
	}
    return 0;
}
