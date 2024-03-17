class Solution {
public:
    int maxPathSum(TreeNode* root) {
      int maxi = INT_MIN;
      findMaxPathSum(root,maxi);
      return maxi;  
    }
private:
    int findMaxPathSum(TreeNode* node , int& maxi){
        if(!node) return 0;

        int leftpath = max(0, findMaxPathSum(node->left , maxi));
        int rightpath = max(0, findMaxPathSum(node->right , maxi));
        int x = node->val;

        maxi = max(maxi , (leftpath+rightpath) + x);
        return max(leftpath,rightpath)+x;
    }
};