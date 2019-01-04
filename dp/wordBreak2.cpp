//https://practice.geeksforgeeks.org/problems/word-break-part-2/0/?track=sp-recursion

#include<bits/stdc++.h>

using namespace std;

unordered_set<string> dict;

unordered_map<int,vector<string>> memo;

vector<string> giveAns(string s,int i){
    vector<string> res;
    if(s==""){
        res.push_back(" ");
        return res;
    }else{
        for(int i=1;i<=s.size();i++){
            string s1=s.substr(0,i);
            string s2;
            if(i==s.size()){
                s2="";
            }else{
                s2=s.substr(i,s.size());
            }
            if(dict.find(s1)!=dict.end()){
                vector<string> res2=giveAns(s2,i);
                for(int j=0;j<res2.size();j++){
                    res.push_back(s1+" "+res2[j]);
                }
            }
        }
    }
    //sort(res.begin(),res.end());
    return res;
}

int main(){
	int t,n;
	string s1;
	scanf("%d",&t);
	while(t){
	    dict.clear();
	    memo.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin>>s1;
            dict.insert(s1);
        }
        string s;
        cin>>s;
        vector<string> ans=giveAns(s,0);
        for(int i=0;i<ans.size();i++){
            ans[i].erase(ans[i].size()-1);
            ans[i].erase(ans[i].size()-1);
            cout<<"("<<ans[i]<<")";
        }
        printf("\n");
		t--;
	}

}