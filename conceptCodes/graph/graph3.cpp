// A Quick implementation of BFS using 
// vectors and queue 
#include <bits/stdc++.h> 
#define pb push_back 
  
using namespace std; 
  
unordered_set<int> visited; 
unordered_map<int, vector<int> > g; 
  
void edge(int a, int b) 
{ 
    std::vector<int> v;
    v=g[a];
    v.pb(b);
    g[a]=v; 
  
    // for undirected graph add this line 
     //g[b].pb(a); 
} 
  
void bfs(int u) 
{ 
    visited.clear();
    queue<int> q; 
  
    q.push(u); 
   visited.insert(u); 
  
    while (!q.empty()) { 
  
        int f = q.front(); 
        q.pop(); 
  
        cout << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (visited.find(*i)==visited.end()) { 
                q.push(*i); 
               visited.insert(*i);  
            } 
        } 
    } 
}

void dfs(int u){
    visited.clear();
    stack<int> s;
    s.push(u);
     while (!s.empty()) { 
  
        int f = s.top(); 
        s.pop(); 
  
        cout << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (visited.find(*i)==visited.end()) { 
                s.push(*i); 
               visited.insert(*i);  
            } 
        } 
    } 

}

void dfsR(int u){
   cout<<u<<" "; 
   visited.insert(u);
   for (auto i = g[u].begin(); i != g[u].end(); i++) { 
            if (visited.find(*i)==visited.end()) { 
                dfsR(*i); 
               //visited.insert(*i);  
            } 
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
    dfsR(4);
  //IMPORTant check the difference in output of dfs and dfsR
    return 0; 
} 