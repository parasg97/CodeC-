#include <bits/stdc++.h>

#define ll long long
#define pb push_back
using namespace std;

//https://www.hackerrank.com/challenges/coin-change/problem


int main(){
    int n,csize;
    scanf("%d%d",&n,&csize);
    vector<ll> c(csize,0);
    vector<ll> ans(n+1,0);
    ans[0]=1;
    for(int i=0;i<csize;i++){
        ll temp;
        scanf("%lld",&c[i]);
        
    }
    //cout<<c[2]<<endl;
    for(int i=0;i<csize;i++){
        for(int j=c[i];j<=n;j++){
            ans[j]+=ans[j-c[i]];
        }
    }
   cout<<ans[n];
}
