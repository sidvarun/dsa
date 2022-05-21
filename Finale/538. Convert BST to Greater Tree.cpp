/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int currSum;
    
    void dfs(TreeNode* root){
        
        if(!root)
            return;
        
        dfs(root->right);
        int temp = root->val;
        root->val += currSum;
        currSum += temp;
        dfs(root->left);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        
        currSum = 0;
        
        dfs(root);
        
        return root;
    }
};