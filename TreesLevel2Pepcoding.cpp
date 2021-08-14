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
// 98. Validate Binary Search Tree - https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool solve(TreeNode* root, int* l, int* h){
        if(root == NULL)
            return true;
        bool lchild = solve(root->left, l, &root->val);
        bool rchild = solve(root->right, &root->val, h);
        if((l && root->val <= *l) || (h && root->val >= *h))
            return false;
        return lchild && rchild;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
};
/******************************************************************************************/
// Vertical width of Binary tree | Set 1 (Width of the shadow of a binary tree) - https://www.geeksforgeeks.org/width-binary-tree-set-1/

void lengthUtil(Node* root, int &maximum,
                int &minimum, int curr=0)
{
    if (root == NULL)
        return;
  
    // traverse left
    lengthUtil(root->left, maximum,
               minimum, curr - 1);
  
    // if curr is decrease then get
    // value in minimum
    if (minimum > curr)
        minimum = curr;
  
    // if curr is increase then get
    // value in maximum
    if (maximum < curr)
        maximum = curr;
  
  
    // traverse right
    lengthUtil(root->right, maximum,
               minimum,  curr + 1);
  
}
  
int getLength(Node* root)
{
    int maximum = 0, minimum = 0;
    lengthUtil(root, maximum, minimum, 0);
  
    // 1 is added to include root in the width
    return (abs(minimum) + maximum) + 1;
}
/**********************************************************************/
// Vertical Traversal of Binary Tree - https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code herevector<vector<int>> res;
        map<int, vector<int>> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            Node* curr = p.first;
            int level = p.second;
            // res[level].push_back(curr->val);
            m[level].push_back(curr->data);
            if(curr->left)
                q.push({curr->left, level - 1});
            if(curr->right)
                q.push({curr->right, level + 1});
        }
        vector<int> temp;
        for (auto itr = m.begin(); itr != m.end(); ++itr) {
            for(auto i : itr->second)
                temp.push_back(i);
        }
        return temp;
    }
};
/********************************************************************/
// 199. Binary Tree Right Side View - https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int> res;
       if(!root)
        return res;
       queue<TreeNode *> q;
       q.push(root);
       while(!q.empty()){
           int count = q.size();
           for(int i = 0; i<count; i++){
               TreeNode *curr = q.front();
               q.pop();
               if(i == count - 1)
                res.push_back(curr->val);
               if(curr->left)
                q.push(curr->left);
               if(curr->right)
                q.push(curr->right);
           }
       }
       return res;
    }
};
/****************************************************************************/
// Top View of Binary Tree  - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
/*
    use same concept as vertical order traversal. 
    Maintain  a map, and a queue of pairs. do level order traversal and while pushing each node int the queue,
    push the current vertical level.
    While popping an element front the front of the queue, check if this is the first element of the level by using m.find(level) == m.end()
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            Node* curr = p.first;
            int level = p.second;
            // res[level].push_back(curr->val);
            if(m.find(level) == m.end())
                m[level] = (curr->data);
            if(curr->left)
                q.push({curr->left, level - 1});
            if(curr->right)
                q.push({curr->right, level + 1});
        }
        vector<int> res;
        for (auto itr = m.begin(); itr != m.end(); ++itr) {
                res.push_back(itr->second);
        }
        return res;
    }

};
/***********************************************************************************/
// Diagonal Traversal of Binary Tree - https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1#
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> res;
   queue<Node* >q;
   q.push(root);
   while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        res.push_back(curr->data);
        if(curr->left)
            q.push(curr->left);
        while(curr->right){
            res.push_back(curr->right->data);
            if(curr->right->left)
                q.push(curr->right->left);
            curr = curr->right;
        }
   }
   return res;
}
// 
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> res;
   queue<Node* >q;
   q.push(root);
   while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        res.push_back(curr->data);
        if(curr->left)
            q.push(curr->left);
        while(curr->right){
            res.push_back(curr->right->data);
            if(curr->right->left)
                q.push(curr->right->left);
            curr = curr->right;
        }
   }
   return res;
}
// Vertical sum  - https://practice.geeksforgeeks.org/problems/vertical-sum/1

class Solution{
    public:
        vector <int> verticalSum(Node *root) {
        // add code here.
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            Node* curr = p.first;
            int level = p.second;
            // res[level].push_back(curr->val);
            m[level] += (curr->data);
            if(curr->left)
                q.push({curr->left, level - 1});
            if(curr->right)
                q.push({curr->right, level + 1});
        }
        vector<int> temp;
        for (auto itr = m.begin(); itr != m.end(); ++itr) {
                temp.push_back(itr->second);
        }
        return temp;
    }
};
/**************************************************************************************/
// Serialize and Deserialize a Binary Tree  - https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

class Solution
{
    public:
    int i = 0;
    //Function to serialize a tree and return a list containing nodes of tree.
    void preorder(Node* root, vector<int> &res){
        if(root == NULL){
            res.push_back(-1);
            return;
        }
        res.push_back(root->data);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    //Function to deserialize a list and construct the tree.
    Node* solve(int n, vector<int> v){
        if(i == n)
            return NULL;
        int val = v[i];
        i++;
        if(val == -1)
            return NULL;
        Node* root = new Node(val);
        root->left = solve(n, v);
        root->right = solve(n, v);
        return root;
    }
    Node* deSerialize(vector<int> &A)
    {
       //Your code here
        return solve(A.size(), A);
    }

};
/****************************************************************************/