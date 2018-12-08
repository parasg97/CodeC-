//https://www.interviewbit.com/problems/level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<pair<TreeNode* ,int >> q;//node,level
    vector<vector<int> > result;
    TreeNode* root=A;
    int l=0;
    q.push(pair<TreeNode*,int>(root,1));
    vector<int> v;
    while(!q.empty()){
        pair<TreeNode*,int> p=q.front();
        //cout<<"r "<<p.first->val<<endl;
        q.pop();
        if(p.second==l){
            v.push_back(p.first->val);
        }else{
            if(!v.empty()){
                result.push_back(v);
            }
            v.clear();
            l++;
            v.push_back(p.first->val);
        }
        if(p.first->left!=NULL){
           q.push(pair<TreeNode*,int>(p.first->left,l+1)); 
        }
        if(p.first->right!=NULL){
           q.push(pair<TreeNode*,int>(p.first->right,l+1)); 
        }
        if(q.empty()){
            result.push_back(v);
        }
        
    }
    return result;
}
