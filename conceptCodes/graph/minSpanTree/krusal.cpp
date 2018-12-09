//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> size;//keep track of number of nodes in subsets
unordered_map<int,int> g;//node and its parent
multimap<int,pair<int,int>>m;//edge weight,node a to node b


int findParent(int a){
	while(g[a]!=a){
		//a=g[a];
		a=g[g[a]];//path compresion
	}
	return a;
}

void doUnion(int a,int b){
	int p1=findParent(a);
	int p2=findParent(b);
	if(size[p1]>size[p2]){
		g[p2]=p1;
		size[p1]+=size[p2];
	}else{
		g[p1]=p2;
		size[p2]+=size[p1];
	}
}


int main(){
	int n,e;
	int w,u,v;
	int ans=0;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>u>>v>>w;
		g[u]=u;
		size[u]=1;
		g[v]=v;
		size[v]=1;
		//m[w]=make_pair(u,v);
		m.insert(make_pair(w,make_pair(u,v)));
	}
	for(auto itr=m.begin();itr!=m.end();itr++){
	    int n1=itr->second.first;
	    int n2=itr->second.second;
	    int p1=findParent(n1);
	    int p2=findParent(n2);
	    if(p1!=p2){
	        ans=ans+itr->first;
	        doUnion(n1,n2);
	    }
	}
	
	cout<<ans<<endl;
	
}