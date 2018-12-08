#include <bits/stdc++.h>

using namespace std;

/*unordered_map< int, unordered_set<int> >m;

unordered_map< int, unordered_map<int,int> >m;

//adding a node in map
void addNode(int a,int b){
	unordered_set<int> s;
    if(m.find(a)!=m.end()){
    	s=g[a];
    }
    s.insert(b);
    g[a]=s;
}

//with weights
void addNodeW(int a,int b,int w){
	unordered_map<int,int> i;
    if(m.find(a)!=m.end()){
    	i=g[a];
    }
    s.insert(pair<int,int>(b,w));
    g[a]=i;
}

//retrive info
//oneDirectional
void isEdgePresent(int a,int b){
	unordered_set<int> s;
        if(m.find(a)!=m.end()){
            s=g[a];
            if(s.find(b)!=s.end()){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
}

//bidirectional
bool isEdgePresent(int a,int b){
	unordered_set<int> s;
        if(m.find(a)!=m.end()){
            s=g[a];
            if(s.find(b)!=s.end()){
                return true;
            }
        }
        if(m.find(b)!=m.end()){
        	s=g[b];
            if(s.find(a)!=s.end()){
                return true;
            }
        }
        return false;
        
}*/

/*void printmap(){
	for(auto itr=m.begin();itr!=m.end();itr++){
    	cout<<"r "<<itr->first<<"->";
    	unordered_set<int> s;
    	s=itr->second;
    	for(auto itr2=s.begin();itr2!=s.end();itr2++){
    		cout<<*itr2<<"->";
    	}
    	cout<<endl;

    }
}
*/

int main(int argc, char const *argv[])
{
	/*//directed without weights
	unordered_map< int, unordered_set<int> >g;

	//directed with weights
	unordered_map< int, unordered_map<int,int> >g; //inside map contains key as node and value as weight

	//for undirected graphs check both  nodes as key


	//BFS Applications:
	//1. level of nodes
	//2. 0-1 BFS - finding shortest dist b/w 2nodes
	return 0;*/

	int n;
	unordered_map< int, unordered_set<int> >m;
	queue<int> q;
    cin>>n;
    vector<int> level(n+1);
    int a,b;
    for(int i=0;i<(n-1);i++){
        cin>>a>>b;
        unordered_set<int> s;
        if(m.find(a)!=m.end()){
    	    s=m[a];
        }
        s.insert(b);
        m[a]=s;
    }
    for(auto itr=m.begin();itr!=m.end();itr++){
    	cout<<"r "<<itr->first<<"->";
    	unordered_set<int> s;
    	s=itr->second;
    	for(auto itr2=s.begin();itr2!=s.end();itr2++){
    		cout<<*itr2<<"->";
    	}
    	cout<<endl;

    }
    
    /*level[1]=1;
    q.push(1);
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        unordered_set<int> s;
        if(m.find(parent)==m.end()){
        	continue;
        }
        s=m[parent];
        for(auto itr=s.begin();itr!=s.end();itr++){
            //cout<<"c "<<*itr<<endl;
            level[*itr]=level[parent]+1;
            q.push(*itr);
        }
    }
    int ans=0;
    int x;
    cin>>x;
   // cout<<"x: "<<x<<endl;
    for(int i=1;i<level.size();i++){
      //  cout<<"l "<<level[i]<<endl;
        if(level[i]==x){
            ans++;
        }
    }
    cout<<ans<<endl;*/
}