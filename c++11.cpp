#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <tuple>
#include <functional>
#include <memory>

using namespace std;
void F(int a){
	cout<<"int:"<<a<<endl;
}
void F(int *pa){
	cout<<"int *:"<< pa <<endl;
}
void PrintVector(const vector<int> & vi){
	cout<< "[";
	for(auto it = vi.begin(); it != vi.end(); ++it){
		cout<< *it <<",";
	}
	cout<< "]" <<endl;
}
struct Sum{
	Sum(){sum=0;}
	void operator()(int n){ sum += n; }
	int sum;
};

template<typename T>
void Print(T t){
    cout<< t <<endl;  
} 
template<typename Head, typename... Tail>  
void Print(Head head, Tail... tail) {  
    cout<< head <<", ";  
    Print(tail...);  
} 
class Foo{
public:
	Foo(){ cout<< "Foo construct."<< this  <<endl;}
	~Foo(){ cout<< "Foo destruct."<< this <<endl; }
	int val;
	void bar(){ cout<< "Foo.bar() called."<< val <<endl; }
};
int main(){
	/****************************************/
	auto i = 12345678;
	auto s = "Hello中国";
	auto f = 3.14;
	vector<int> vi {9,8,7,1,2,3,4};
	decltype(f) d = 6.28;
	cout<<"未排序的vector:"<<endl;
	PrintVector(vi);
	//sort(vi.begin(),vi.end(),greater<int>());
	sort(vi.begin(),vi.end(),less<int>());
	cout<<"排序后的vector:"<<endl;
	PrintVector(vi);
 
	cout<< i << endl;
	cout<< s << endl;
	cout<< f << endl;
	// old style: vector<int>::iterator it = vi.begin()
	cout<< endl;
	cout << "decltype(x):"  << d <<endl;
	/****************************************/
	// NULL vs. nullptr
	int a = 0;
	int *pa = nullptr;
	int *pb = NULL;
	F(a);
	F(pa);
	F(pb);
	bool bEqual = (pa == pb);
	cout<< bEqual <<endl;
	/****************************************/
	// for_each
	map<string,int> m1 {
			{"Hello中国",110},
			{"美国",345},
			{"Japan",000}
		};
	for(auto item: m1){
		cout<<"Key:"<<item.first<<",Value:"<<item.second<<endl;
	}
	for_each(vi.begin(),vi.end(),[](int & x){ x*=2; } );
	PrintVector(vi);
 	// Calls Sum::operator() for each number
	Sum sum1 = for_each(vi.begin(),vi.end(),Sum());
	cout<<"Sum:"<<sum1.sum<<endl;
	
	int arg1=1,arg2=2;
	for_each(vi.begin(),vi.end(),[=](int & x){ x *=(arg1+arg2); } );
	PrintVector(vi);
	for_each(vi.begin(),vi.end(),[=](int & x) -> int { return  x *(arg1+arg2); } );
	PrintVector(vi);
	/****************************************/
	// 变长参数模板
	auto pair1 = make_pair(110,"Hello中国");
	cout<< "pair.first:"<<pair1.first<<",pair.second:"<<pair1.second<<endl;
	auto tuple1 = make_tuple("Hello",1,3.14);
	cout<< std::get<0>(tuple1) <<endl;
	cout<< std::get<1>(tuple1) <<endl;
	cout<< std::get<2>(tuple1) <<endl;

	Print(1);
	Print(1,"Hello中国");
	Print(1,"Hello中国",3.1415926);
	cout<< "******************************" <<endl;
	// unique_ptr具有转移语义
	unique_ptr<Foo> p1(new Foo());	
	if(p1) p1->val = 123;
	if(p1) p1->bar();
	{
		unique_ptr<Foo> p2 = std::move(p1);
		p2->val *=2;
		p2->bar();
	}
	if(p1) p1->bar();
	cout<< "******************************" <<endl;
	// shared_ptr
	shared_ptr<Foo> sp1(new Foo());	
	if(sp1) sp1->val = 123;
	if(sp1) sp1->bar();
	{
		shared_ptr<Foo> sp2 = sp1;
		sp2->val *=2;
		sp2->bar();
	}
	if(sp1) sp1->bar();

	return 0;
}
