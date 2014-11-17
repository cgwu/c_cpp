#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> words;
    string next_word;
    while (cin >> next_word)
    {
        words.push_back(next_word);
    }
    cout<<"----------"<<endl;
    for(string s :words){
        cout<<s<<endl;
    }
    cout<<"done."<<endl;
    return 0;
}
