#include <bits/stdc++.h>

using namespace std;

vector<string> giveTokens(string s,string del){
    
}

int main(){
    int n;
    cin>>n;
    string s,temp;
    getline(cin,temp);
    getline(cin,s);
    cout<<s<<endl;
    string word;
    int start=0;
    while(true){
        int temp=s.find(",",start);
        if(temp==string::npos){
            cout<<s.substr(start,s.size());
            break;
        }
        word=s.substr(start,temp-start+1);
        start=temp+1;
        cout<<word<<endl;
    }
}