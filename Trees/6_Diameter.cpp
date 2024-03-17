class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int diameter = 0;
       height(root,diameter) ;
       return diameter;
    }
private:
    int height(TreeNode* node, int& diameter){
        if(!node) return 0;

        int lh = height(node->left,diameter);
        int rh = height(node->right,diameter);

        diameter = max(lh+rh , diameter);

        return max(lh,rh)+1;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(h) where h is the height of the tree