#include <iostream>
#include <string>

using namespace std;
class T{};
struct S{};
struct __ST{
    char a;
    unsigned int b:5,
        c:11,
        :0,
        d:8;
    struct {int ee:8;} e;
} st;
struct __E{int ee:8;} e1;
int main(){
	cout<<"是中国人，我爱中国"<<endl;
    cout<< sizeof(int) <<endl;
    cout<< sizeof(T) <<endl;
    cout<< sizeof(S) <<endl;
    cout<< "自定义结构:"<<sizeof(st) <<endl;
    cout<< "自定义结构e1:"<<sizeof(e1) <<endl;
    st.b = 32 -1;
    cout<< "st.b=" << st.b <<endl;
    st.b ++ ;
    cout<< "st.b=" << st.b <<endl;
    cout<< "st.c=" << st.c <<endl;
    const char * sr = "(\
        hello中国\
        abc \
        )";
    cout<< sr <<endl;

	return 0;
}
