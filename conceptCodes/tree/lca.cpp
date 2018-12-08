/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    TreeNode findLCA(TreeNode root,int a,int b){
        if(root==null){
            return null;
        }
        if(root.val==a || root.val==b){
            return root;
        }
        
        TreeNode leftLca=findLCA(root.left,a,b);
        TreeNode rightLca=findLCA(root.right,a,b);
        
        if(leftLca!=null && rightLca!=null){
            return root;
        }
        else{
            if(leftLca==null){
                return rightLca;
            }else{
                return leftLca;
            }
        }
        
        
    }
    
    TreeNode findNode(TreeNode root,int a){
        if(root==null){
            return null;
        }
        if(root.val==a){
            return root;
        }
        TreeNode left=findNode(root.left,a);
        TreeNode right=findNode(root.right,a);
        
        if(left==null){
            return right;
        }else{
            return left;
        }
    }
    public int lca(TreeNode A, int B, int C) {
        TreeNode left=findNode(A,B);
        TreeNode right=findNode(A,C);
        if(left==null || right==null){
            return -1;
        }else{
            TreeNode ans=findLCA(A,B,C);
            return ans.val;
        }
    }
}
