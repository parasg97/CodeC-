#include <bits/stdc++.h>

#define pb push_back

using namespace std;


unordered_map<int,int> uf; // node , parent
multimap<int,pair<int,int>> pq;//priority queue , weight/u and v
unordered_map<int,int> size;



int findParent(int a){
    while(uf[a]!=a){
        a=uf[uf[a]];
    }
    return a;
}

void doUnion(int a,int b){
    int p1=findParent(a);
    int p2=findParent(b);
    if(p1==p2){
        return;
    }else{
        if(size[p1]>size[p2]){
            uf[p2]=p1;
            size[p1]+=size[p2];
        }else{
            uf[p1]=p2;
            size[p2]+=size[p1];
        }
    }
}


int main() {
    int n,e,w;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d%d%d",&u,&v,&w);
        uf[u]=u;
        uf[v]=v;
        size[u]=1;
        size[v]=1;
        pq.insert({w,{u,v}});
    
    }
    int ans=0;
    while(!pq.empty()){
        auto itr=pq.begin();
        int u=itr->second.first;
        int v=itr->second.second;
        int p1=findParent(u);
        int p2=findParent(v);
        if(p1!=p2){
            ans+=itr->first;
            doUnion(u,v);
        }
        pq.erase(itr);
    }
    cout<<ans<<endl;
}


