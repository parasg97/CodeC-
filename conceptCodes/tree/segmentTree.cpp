#include <bits/stdc++.h>

using namespace std;

static vector<int> tree(100000);
static int arrSize; 

void buildSegTree(int arr[], int node ,int left, int right){
	if(left==right){
	    tree[node]=arr[left];
	}else{
	    int mid=(left+right)/2;
	    buildSegTree(arr,2*node,left,mid);
	    buildSegTree(arr,2*node+1,mid+1,right);
	    tree[node]=tree[2*node]+tree[2*node+1];
	}


}

void updateTree(std::vector<int> tree,int index,int val,int node,int left,int right){
	if(left==right){
		tree[node] = val;
	}else{
		if(left<=index && right>=index){
			int mid = (left+right)/2;
			if(left<=index && mid>=index){
				updateTree(tree,index,val,2*node,left,mid);
			}else if((mid+1)<=index && right>=index){
				updateTree(tree,index,val,2*node+1,mid+1,right);
			}
			tree[node] = tree[2*node]+tree[2*node+1];
		}else{
			return;
		}
	}
}

int queryTree(std::vector<int> tree,int node,int leftT,int rightT,int rangeL,int rangeR){
	if(leftT==rangeL and rightT==rangeR){
	    return tree[node];
	}
	else if(rangeR<leftT || rangeL>rightT){
	    return 0;
	}
	else{
	    int mid=(leftT+rightT)/2;
	    int a1=queryTree(tree,2*node,leftT,mid,rangeL,min(mid,rangeR));
	    int a2=queryTree(tree,(2*node)+1,mid+1,rightT,max(mid+1,rangeL),rangeR);
	    return a1+a2;
	}
}


int main(int argc, char const *argv[])
{
	//int arr[10] = {1,45,65,7,88,23,6,2,78,63};
	int arr[4] = {1,3,5,7};
	//int arrSize = 10;
	int arrSize =4;
	int treeSize = 2*arrSize - 1;
	buildSegTree(arr,1,0,arrSize-1);
	for (int i = 1; i <= treeSize; ++i)
	{
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	//updateTree(std::vector<int> tree,int index,int val,int node,int left,int right)
	//updateTree(tree,2,6,1,0,3);
	/*for (int i = 1; i <= treeSize; ++i)
	{
		cout<<tree[i]<<" ";
	}
	cout<<endl;*/
	cout<<queryTree(tree,1,0,arrSize-1,1,3)<<endl;

}