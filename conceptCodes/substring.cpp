#include <bits/stdc++.h>

using namespace std;

//sorted 
void subStrs(string const s){
	for (int i = 1; i <=s.size(); ++i)
	{
		for (int j = 0; j < s.size(); ++j)
		{
			if(j+i>s.size()){
				break;
			}
			cout<<s.substr(j,i);
		}
	}

}

void subStr(string s){
	for (int i = 0; i < s.size(); ++i)
	{	
		string temp="";
		for (int j = i; j < s.size(); ++j)
		{
			temp.push_back(s[j]);
			cout<<temp<<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}