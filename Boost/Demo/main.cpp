#include <iostream>
#include <cstdio>
#include <boost/log/trivial.hpp>
#include <boost/regex.hpp>

int main(int argc, char** argv) {
	
	using namespace std;
	using namespace boost;
 	/*
 	std::string in;
	cmatch what;
	//cout<<"enter test string"<< endl;
	//getline(cin,in);
	in = "select name from table";
	regex expression("^select ([a-zA-Z]*) from ([a-zA-Z]*)");
	if(regex_match(in.c_str(), what, expression))
	{
		for(int i=0;i<what.size();i++)
			cout<<"str :"<<what[i].str()<<endl;
	}
	else
	{
		cout<<"Error Input"<<endl;
	}
	*/
	cout << "--------------" << endl;
 
 	// 动态库需要定义: -DBOOST_LOG_DYN_LINK  
	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
    
	//getchar();
	return 0;
}
