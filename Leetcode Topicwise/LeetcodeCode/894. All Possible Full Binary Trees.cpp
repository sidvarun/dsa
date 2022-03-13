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
    vector<TreeNode*> res;
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> dfs(int n){
        if(n == 0)
            return vector<TreeNode*>{};
        
        if(n == 1)
            return vector<TreeNode*>{new TreeNode(0)};
        
        if(memo.find(n) != memo.end())
            return memo[n];
        vector<TreeNode*> res;
        for(int i = 0; i < n; i++){
            vector<TreeNode*> left = dfs(i);
            vector<TreeNode*> right = dfs(n - i - 1);
            for(auto n1 : left){
                for(auto n2 : right){
                    TreeNode* root = new TreeNode(0, n1, n2);
                    res.push_back(root);
                }
            }
        }
        return memo[n] = res;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return dfs(n);
    }
};