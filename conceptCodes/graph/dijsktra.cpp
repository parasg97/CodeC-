//https://www.hackerrank.com/challenges/dijkstrashortreach/problem

/*
*	The graph is bidirectional
*	Nodes can have multiple edges i.e. between any 2 nodes there can be more than 1 edge
*/


#include <bits/stdc++.h>

using namespace std;

unordered_map<int,vector<pair<int,int>>> g;//node.. neighbours/weight
unordered_set<int> visited;
multimap<int,int> pq;//current dist from root/node

int main(){
    int t;
    cin>>t;
    while(t>0){
        g.clear();
        visited.clear();
        pq.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
          int u, v, w;
          cin >> u >> v >> w;
          g[u].push_back({v,w});
          g[v].push_back({u, w});
        }
        vector<int> res(n + 1, -1);
        int s;
        cin >> s;
        res[s] = 0;
        visited.insert(s);
        pq.insert({0, s});
        while (!pq.empty()) {
          int node = pq.begin()->second;
          pq.erase(pq.begin());
          vector<pair<int, int>> child = g[node];
          for (int i = 0; i < child.size(); i++) {
            int c = child[i].first;
            int w = child[i].second;
            if (res[c]==-1 || res[node] + w < res[c]) {
            //update the priority queue
              for (auto itr = pq.begin(); itr != pq.end(); itr++) {
                if (itr->second == c) {
                  pq.erase(itr);
                  pq.insert({res[node] + w, c});
                  break;
                }
              }
              //update the result vector
              res[c] = res[node] + w;
            }
            if (visited.find(c) == visited.end()) {
              visited.insert(c);
              pq.insert({res[c], c});
            }
          }
        }
       
        for(int i=1;i<=n;i++){
            if(s==i){
                continue;
            }
            cout<<res[i]<<" ";
        }
        cout<<endl;
        t--;
    }
}

