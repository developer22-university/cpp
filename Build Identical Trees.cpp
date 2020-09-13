public class Solution {
     public int cntMatrix(TreeNode A, TreeNode B) {
        return cntMatrixUtil(A,B,Integer.MIN_VALUE,Integer.MAX_VALUE);

    }

    public int cntMatrixUtil(TreeNode A, TreeNode B, int min,int max) {
        if(A!=null && B==null)
           return -1;
        int inserts=-1;
        if(A!=null && B!=null)inserts = 0;
        else inserts = 1;
        if(B==null && A==null)return 0;
        if(B !=null && A ==null)A = new TreeNode(min+(max-min)/2);
        int left = cntMatrixUtil(A.left, B.left, min, A.val);
        int right = cntMatrixUtil(A.right, B.right, A.val, max);
        if(left==-1 || right ==-1)return -1;
        return inserts + left + right;
    }
}
