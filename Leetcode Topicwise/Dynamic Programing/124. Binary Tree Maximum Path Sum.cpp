// https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603423/Python-Recursion-stack-thinking-process-diagram
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
    int res;
    int rec(TreeNode* root){
        if(root == NULL)
            return 0;
        int lsum = max(0, rec(root->left));
        int rsum = max(0, rec(root->right));
        res = max(res, root->val + lsum + rsum);
        return root->val + max(0, max(lsum, rsum));
    }
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        int x = rec(root);
        return res;
    }
};

