#include<bits/stdc++.h>

#define pf push_front

using namespace std;


deque<int> res;
unordered_map<int,set<int>>g;
unordered_set<int> visited;
unordered_map<int, int> ind; 
set<int> zeroDeg;

void indegree(){
	for(auto itr=g.begin();itr!=g.end();itr++){
        set<int> v=itr->second;
        for(auto itr2=v.begin();itr2!=v.end();itr2++){
            ind[*itr2]+=1;
        }
        if(ind.find(itr->first)==ind.end()){
        	ind[itr->first]=0;
        }
    }
    for(auto itr=ind.begin();itr!=ind.end();itr++){
    	//cout<<itr->first<<" "<<itr->second<<endl;
       if(itr->second==0){
       		zeroDeg.insert(itr->first);
       }
    }


}

void topSort(int u){
    set<int> temp;
    temp=g[u];
    for(auto itr=temp.rbegin();itr!=temp.rend();itr++){
        if(visited.find(*itr)==visited.end()){
            visited.insert(*itr);
            topSort(*itr);
        }
    }
    res.pf(u);
}

int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int u,v;
         scanf("%d%d",&u,&v);
         set<int> temp;
         auto itr=g.find(u);
         if(itr!=g.end()){
             
         temp=g[u];
         }
         temp.insert(v);
         g[u]=temp;
    }
    indegree();
    for(auto itr=zeroDeg.rbegin();itr!=zeroDeg.rend();itr++){
        visited.insert(*itr);
        topSort(*itr);
    }
    
    for(int i=0;i<res.size();i++){
        printf("%d ",res[i]);
    }
}