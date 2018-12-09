

#include <bits/stdc++.h> 
#define pb push_back 
  
using namespace std; 
  
unordered_set <int> visited;
unordered_map< int, vector< pair<int,int> > > g;//node,neighbour/weight
multimap<int,int> pq;//current dist from root,node

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> res(n+1,INT_MAX);
	res[1]=0;

	for (int i = 0; i < m; ++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(make_pair(v,w));
	}
	pq.insert(make_pair(0,1));
	visited.insert(1);
	while(!pq.empty()){
		int n=pq.begin()->second;
		int w=pq.begin()->first;
		pq.erase(pq.begin());
		std::vector< pair<int,int> > v=g[n];
		for(int i=0;i<v.size();i++){
			res[v[i].first]=min(res[n]+v[i].second,res[v[i].first]);
			if(visited.find(v[i].first)==visited.end()){
				pq.insert(make_pair(res[v[i].first],v[i].first));
				visited.insert(v[i].first);
			}
		}
	}
	for(int i=2;i<res.size();i++){
		cout<<res[i]<<" ";
	}
}

