#include<bits/stdc++.h>

using namespace std;

set<pair<int,int>> visited;

bool isPossible(vector<vector<int>> v,int x,int y,int n,int m){
    if(x>n || y>m || x<0 || y<0){
        return false;
    }
    if(v[x][y]==0){
        return false;
    }
    if(x==n and y==m){
        return true;
    }
    if(visited.find({x,y})!=visited.end()){
        return false;
    }
    visited.insert({x,y});
    if(isPossible(v,x-1,y,n,m) || isPossible(v,x,y-1,n,m) || 
    isPossible(v,x+1,y,n,m) || isPossible(v,x,y+1,n,m)){
        return true;
    }
    return false;
}

int main(){
    int n,m,temp;
    scanf("%d%d",&n,&m);
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&temp);
            v[i+1][j+1]=temp;
        }
    }
    if(isPossible(v,1,1,n,m)){
       printf("Yes"); 
    }else{
        printf("No");
    }
}