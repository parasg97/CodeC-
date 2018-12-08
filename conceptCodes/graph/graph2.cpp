// A Quick implementation of BFS using 
// vectors and queue 
#include <bits/stdc++.h> 
#define pb push_back 
  
using namespace std; 
  
unordered_set<int> visited; 
vector<vector<int> > g; 
  
void edge(int a, int b) 
{ 
    g[a].pb(b); 
  
    // for undirected graph add this line 
     g[b].pb(a); 
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
  
// Driver code 
int main() 
{ 
    int n, e; 
    cin >> n >> e; 
  
     
    g.assign(n+1, vector<int>()); 
  
    int a, b; 
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        edge(a, b); 
    } 
  
    bfs(3);
    cout<<endl;
    dfs(3);
  
    return 0; 
} 