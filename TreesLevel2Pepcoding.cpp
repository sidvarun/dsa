// 968. Binary Tree Cameras - https://leetcode.com/problems/binary-tree-cameras/
// Explanation - https://leetcode.com/problems/binary-tree-cameras/discuss/1211695/JS-Python-Java-C%2B%2B-or-Easy-Recursive-DFS-Solution-w-Explanation
/*
 Condider 3 states : 
 -1 : node will need a camera
  0 : node itself has a camera
  1 : node doesn't have the camera but its child has covered it so it doesn't need a camera.
*/
class Solution {
public:
    int cameras;
    int solve(TreeNode* root){
        if(!root)
            return 1;
        int lchild = solve(root->left);
        int rchild = solve(root->right);
        if(lchild == -1 || rchild == -1){
            cameras++;
            return 0;
        }
        if(lchild == 0 || rchild == 0)
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        if(solve(root) == -1) /*if the root returns -1 means none of its child covered it withe there camera so it will need a camera for itself, hence we add 1 to the count of the cameras.*/
            cameras++;
        return cameras;
    }
};
/****************************************************************************************/
// 1372. Longest ZigZag Path in a Binary Tree - https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
class Solution {
public:
    pair<int, pair<int, int>> solve(TreeNode* root){
        pair<int, pair<int, int>> rootPair = {0, {-1, -1}};
        if(root == NULL)
            return rootPair;
        pair<int, pair<int, int>> lchild = solve(root->left);
        pair<int, pair<int, int>> rchild = solve(root->right);
        rootPair.first = max(max(lchild.first, rchild.first), 1 + max(lchild.second.second,  rchild.second.first));
        rootPair.second.first = lchild.second.second + 1;
        rootPair.second.second = rchild.second.first + 1;

        return rootPair;
        
    }
    int longestZigZag(TreeNode* root) {
        pair<int, pair<int, int>> res = solve(root);
        return res.first;
    }
};
/******************************************************************************************/
// 337. House Robber III - https://leetcode.com/problems/house-robber-iii/
// Solution Explanation - https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
class Solution {
public:
    pair<int, int> solve(TreeNode* root){
        pair<int, int> subres = {0,0};
        if(root == NULL)
            return subres;
        pair<int, int> lchild = solve(root->left);
        pair<int, int> rchild = solve(root->right);
        subres.first = root->val + lchild.second + rchild.second;
        subres.second = max(lchild.first, lchild.second) + max(rchild.first, rchild.second);
        return subres;
    }
    int rob(TreeNode* root) {
        pair<int, int> res = solve(root);
        return max(res.first, res.second);
    }
};
/*********************************************************************************************/
