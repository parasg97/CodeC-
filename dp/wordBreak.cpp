#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string temp,q,tp;
	unordered_set<string> s;
	for(int i=0;i<n;i++){
		cin>>temp;
		s.insert(temp);
	}
	cin>>q;
	string res="";
	for (int i = 0; i < q.size(); ++i)
	{	
		temp="";
		tp="";
		for (int j = i; j < q.size(); ++j)
		{
			temp.push_back(q[j]);
			if(s.find(temp)!=s.end()){
				tp=temp;
				
			}
		}
		cout<<tp<<endl;
		if(!tp.empty()){
			res+=tp;
		}
	}
	cout<<res<<endl;
	if(res==q){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}