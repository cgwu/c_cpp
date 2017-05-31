#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

shared_ptr<int> get_int(int val);

int main(int argc, char* argv [])
{
	vector<int> vi{11,22,33,44};
	for(auto i : vi){
		cout << i << endl;
	}
	for(auto &i : vi){
		i *= 10;
	}
	cout <<"after * 10" << endl;
	for(auto i : vi){
		cout << i << endl;
	}
	int val = 330;
	auto result = find(vi.cbegin(),vi.cend(), val);
	cout << "The value is: " << (result == vi.cend() ? "not present" : "present") << endl;

	int ia[] = {3,1,3,4,5,2,1,4,234};
	int* retia = find(begin(ia), end(ia), 2342);
	cout << (retia == end(ia)) << ",val:" << *retia << endl;
	for(auto i : ia) {
		cout << i << '\t';
	}
	cout << endl;
	fill(begin(ia), end(ia), 0);
	for(auto i : ia) {
		cout << i << '\t';
	}
	cout << endl;
	cout << "sizeof ia: " << sizeof(ia) / sizeof(*ia) << endl;
	shared_ptr<int> spi = get_int(1234);
	cout << *spi << endl;

	return 0;
}

shared_ptr<int> get_int(int val){
	return make_shared<int>(val);
}


