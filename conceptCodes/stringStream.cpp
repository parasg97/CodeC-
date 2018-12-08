#include <bits/stdc++.h>

#define pb push_back

using namespace std;

//string stream
//ss.str() gives the whole stream; But it does not clear the stream
//to clear string stream use both ss.clear() then ss.str("")
//>> out operator
//<< in operator

//getline()
//getline(input stream,output string,delimeter(optional,by default new line charecter))

int main(int argc, char const *argv[])
{
	stringstream ss;
	ss.str("paras gupta");
	string token;
	while(ss>>token){
		
		cout<<token<<endl;
	}
	string s;
	getline(cin,s);
	cout<<endl<<s<<endl;

	ss.clear();
	ss.str("");
	ss<<"paras,gupta,coder";
	cin.ignore();
	while(getline(ss,token,',')){
		cout<<token<<endl;
	}

	cout<<endl;
	ss.clear();
	ss.str("");

	ss.str("123 45");
	int a,b;
	ss>>a;
	ss>>b;

	cout<<a-b<<endl;

}