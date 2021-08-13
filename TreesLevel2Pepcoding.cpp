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