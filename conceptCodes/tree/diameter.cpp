//diameter is the largest dist b/w two nodes

#include <bits/stdc++.h>

using namespace std;

/*struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};*/

int maxVal(int a,int b,int c){
	if(a>b){
		return max(a,c);
	}else{
		return max(b,c);
	}
}

int height(TreeNode* root){
	if(root==NULL){
		return 0;
	}else{
		return (1+max(height(root->left),height(root->right)));
	}
}

//1. for bt
int widthBT(TreeNode* root){
	if(root==NULL){
		return 0;
	}
	//leaf node
	int ans=maxVal(widthBT(root->left),widthBT(root->right),1+height(root->left)+height(root->right));
	return ans;

}


//to calculate hieght in same recursion as well
//ht represents height of that root node
//intitally pass as 0
int widthBTOpt(TreeNode* root,int& ht){
	int lh=0,rh=0;
	int lw=0,rw=0;
	if(root==NULL){
		ht=0;
		return 0;
	}
	lw=widthBTOpt(root->left,lh);
	rw=widthBT(root->right,rh);
	ht=max(lh,rh)+1;
	int ans=maxVal(lw,rw,1+lh+rh);
	return ans;

}


int main(){

}