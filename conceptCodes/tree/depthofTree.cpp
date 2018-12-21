#include <bits/stdc++.h>

using namespace std;

/*struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};*/

int treeDepth(TreeNode* root){
	if(root==NULL){
		return 0;
	}
	else{
		return 1+max(treeDepth(root->left),treeDepth(root->right));
	}
}