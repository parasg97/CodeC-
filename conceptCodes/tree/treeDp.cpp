//https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int ans;
 
 pair<int,int> giveAns(TreeNode* root){
     if(root==NULL){
         return {0,0};
     }
     pair<int,int> p1=giveAns(root->left);//if path passes through this node and one child tree
     pair<int,int> p2=giveAns(root->right);////if path passes through this node and both child trees
     pair<int,int> p={max(root->val,max(p1.first,p2.first)+root->val),
     max(root->val,root->val+p1.first+p2.first)};
     ans=max(ans,max(p.first,p.second));
     return p;
 }
 
int Solution::maxPathSum(TreeNode* A) {
    ans=INT_MIN;
    giveAns(A);
    return ans;
}
