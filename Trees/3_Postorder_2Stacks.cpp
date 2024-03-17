class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
                if(!root) return result;

        stack<TreeNode*> s1;
        stack<TreeNode* > s2;

        s1.push(root);

        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root->left) s1.push(root->left);
            if(root->right) s1.push(root->right);
        }

        while(!s2.empty()){
            result.push_back(s2.top()->val);
            s2.pop();
        }
        return result;
    }
};


/*
Algorithm:
1. Create 2 stacks s1 and s2
2. Push root to s1
3. While s1 is not empty, do the following:
    a. Pop the top element from s1 and push it to s2
    b. If the left child of the popped element is not null, push it to s1
    c. If the right child of the popped element is not null, push it to s1
4. While s2 is not empty, pop the top element and push it to result
5. Return result
    
    */