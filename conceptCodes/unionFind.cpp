#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> size;//keep track of number of nodes in subsets
unordered_map<int,int> g;//node and its parent

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
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		g[temp]=temp;
		size[temp]=1;
	}
	doUnion(1,2);
	doUnion(56,4);
	doUnion(1,4);
	int p=findParent(1);
	cout<<p<<" "<<size[p]<<endl;
}