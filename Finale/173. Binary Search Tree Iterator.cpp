https://leetcode.com/problems/binary-search-tree-iterator/solution/

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
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto res = s.top();
        s.pop();
        TreeNode* curr = res->right;
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        return res->val;
    }
    
    bool hasNext() {
        return s.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */