#include <bits/stdc++.h>

using namespace std;

static vector<int> tree(100000);
static int arrSize; 

void buildSegTree(int arr[], int node ,int left, int right){
	if(left == right){
		tree[node] = arr[left];
	}else{
		int mid = (left + right)/2;
		buildSegTree(arr,2*node,left,mid);
		buildSegTree(arr,(2*node)+1,mid+1,right);
		//for min
		tree[node] = min(tree[2*node],tree[2*node+1]);
		//for sum
		//tree[node] = tree[2*node] + tree[2*node+1];
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
			tree[node] = min(tree[2*node],tree[2*node+1]);
		}else{
			return;
		}
	}
}

int queryTree(std::vector<int> tree,int node,int leftT,int rightT,int rangeL,int rangeR){
	if(rangeL<leftT || rangeR>rightT){
		return -1;
	}else if(){

	}
	if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
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
	updateTree(tree,2,6,1,0,3);
	for (int i = 1; i <= treeSize; ++i)
	{
		cout<<tree[i]<<" ";
	}
	cout<<endl;

}