// A Quick implementation of BFS using 
// vectors and queue 
#include <bits/stdc++.h> 
#define pb push_back 
  
using namespace std; 
  
unordered_set<int> visited; 
unordered_map<int, vector<int> > g; 
unordered_map<int, int> ind; 
set<int> zeroDeg; 
int num;
map<int,int> ans;
  
void edge(int a, int b) 
{ 
    std::vector<int> v;
    v=g[a];
    v.pb(b);
    g[a]=v; 
  
    // for undirected graph add this line 
     //g[b].pb(a); 
} 
  


//using dfs
void topSort(int u){
	if(visited.find(u)!=visited.end()){
        return;
    }
    stack<int> s;
    s.push(u);
    bool allDone=true;
    while (!s.empty()) {
    	allDone=true; 
  		int f = s.top(); 
       	if(g.find(f)==g.end()){
       		s.pop();
       		ans[num]=f;
       		num--;
       	}else{
       		for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            	if (visited.find(*i)==visited.end()) { 
            		allDone=false;
               		s.push(*i); 
               		visited.insert(*i);  
            	} 
        	} 
        	if(allDone){
        		s.pop();
       			d.push_front(f);
        	}
       	}
    }
    
    for(int i=0;i<d.size();i++){
    	cout<<d[i]<<" ";
    } 

}

void traverse(){
    for(auto itr=g.begin();itr!=g.end();itr++){
        cout<<itr->first<<"->";
        std::vector<int> v=itr->second;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<"->";
        }
        cout<<endl;
    }
}

void indegree(){
	for(auto itr=g.begin();itr!=g.end();itr++){
        std::vector<int> v=itr->second;
        for(int i=0;i<v.size();i++){
            ind[v[i]]+=1;
        }
        if(ind.find(itr->first)==ind.end()){
        	ind[itr->first]=0;
        }
    }
    for(auto itr=ind.begin();itr!=ind.end();itr++){
    	cout<<itr->first<<" "<<itr->second<<endl;
       if(itr->second==0){
       		zeroDeg.insert(itr->first);
       }
    }


}
  
// Driver code 
int main() 
{ 
    int n, e; 
    cin >> n >> e; 

  
    int a, b; 
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        edge(a, b); 
    } 
  
    //bfs(4);
    //cout<<endl;
    //dfsR(4);
  //IMPORTant check the difference in output of dfs and dfsR
    //topSort(1);
    //cout<<endl;
    //traverse();
    indegree();
    return 0; 
} 