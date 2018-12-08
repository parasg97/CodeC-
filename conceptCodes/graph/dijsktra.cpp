
#include <bits/stdc++.h> 
#define pb push_back 
  
using namespace std; 
  
unordered_set <char> visited;
unordered_map<char,vector<pair<char,int>> g;//weighted graph
map<char,int> d;//dijsktra helper
unordered_map<char,int> res;//result

void addEdge(char a,char b,int w){
	g[a].pb(pair<char,int>(b,w));

	//if its bidirected
	//g[b].pb(pair<char,int>(a,w));	
}

void findSpath(char root){
	res[root]=0;
	d.insert(root,0);
	while(!d.empty()){
		vector<pair<char,int> v=g[d.begin().first];
		visited.insert(d.begin().first);
		d.pop();

	}
}