
    int maxD(TreeNode root){
        if(root==null){
            return 0;
        }
        if(root.left==null && root.right==null){
            return 1;
        }
        else{
            return (1+max(maxD(root.left),maxD(root.right)));
        }
    }
    
    int maxDepth(TreeNode A) {
        return maxD(A);
    }