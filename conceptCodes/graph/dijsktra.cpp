//https://www.hackerrank.com/challenges/dijkstrashortreach/problem

/*
*	The graph is bidirectional
*	Nodes can have multiple edges i.e. between any 2 nodes there can be more than 1 edge
*/

//https://www.hackerrank.com/challenges/dijkstrashortreach/problem

/*
*	The graph is bidirectional
*	Nodes can have multiple edges i.e. between any 2 nodes there can be more than 1 edge
*/

//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int,vector<pair<int,int>>> g;//node.. neighbours/weight
unordered_set<int> visited;
set<pair<int,int>> pq;//current dist from root/node

int main(){
        int n, m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < m; i++) {
          int u, v, w;
          scanf("%d%d%d",&u,&v,&w);
          g[u].push_back({v,w});
          //g[v].push_back({u, w});
        }
        vector<int> res(n + 1, -1);
        int s;
        s=1;
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
                auto itr = pq.find({res[c],c});
                if(itr!=pq.end()){
                    pq.erase(itr);
                    pq.insert({res[node] + w, c});
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
       
        for(int i=2;i<=n;i++){
//cout<<"SDsd"<<endl;
            if(res[i]==-1){
                printf("%ll ",pow(10,9));
            }else{
                
             printf("%d ",res[i]);
            }
        }
        cout<<endl;
        
    
}

