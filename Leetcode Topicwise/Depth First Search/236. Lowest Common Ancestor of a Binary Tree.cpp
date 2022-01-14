/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res;
    // the functions dfs will return true when either p or q was found in the subtree with root as "root" or when root itself is either p or q
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return false;
        int left = dfs(root->left, p, q) == true ? 1 : 0;
        int right = dfs(root->right, p, q) == true ? 1: 0;
        
        int mid = root->val == p->val || root->val == q->val ? 1 : 0;
        if(left + right + mid == 2){
            res = root;
        }
        return (left + right + mid > 0);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};