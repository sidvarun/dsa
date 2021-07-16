// Level order traversal - https://practice.geeksforgeeks.org/problems/level-order-traversal/1
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int> res;
      queue<Node *> q;
      q.push(root);
      while(!q.empty()){
          Node *curr = q.front();
          q.pop();
          res.push_back(curr->data);
          if(curr->left)
            q.push(curr->left);
          if(curr->right)
            q.push(curr->right);
      }
      return res;
    }
};
/************************************************************************************************/
// Reverse Level Order Traversal - https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> res;
      queue<Node *> q;
      q.push(root);
      while(!q.empty()){
          Node *curr = q.front();
          q.pop();
          res.push_back(curr->data);
          if(curr->right)
            q.push(curr->right);
          if(curr->left)
            q.push(curr->left);
      }
      reverse(res.begin(), res.end());
      return res;
}
/**************************************************************************************************/
// Height of Binary Tree - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here 
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
/********************************************************************************************/
// Diameter of Binary Tree  - https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(struct Node* root){
        // code here 
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void diameterRec(Node* root, int &res){
        if(!root)
            return;
        int subres = 1 + height(root->left) + height(root->right);
        res = max(res, subres);
        diameterRec(root->left, res);
        diameterRec(root->right, res);
    }
    int diameter(Node* root) {
        // Your code here
        int res = INT_MIN;
        diameterRec(root, res);
        return res;
    }
};
/*************************************************************************************************/
// Left View of Binary Tree - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   if(!root)
    return res;
   queue<Node *> q;
   q.push(root);
   while(!q.empty()){
       int count = q.size();
       for(int i = 0; i<count; i++){
           Node *curr = q.front();
           q.pop();
           if(i == 0)
            res.push_back(curr->data);
           if(curr->left)
            q.push(curr->left);
           if(curr->right)
            q.push(curr->right);
       }
   }
   return res;
}
/********************************************************************************************/
// Right View of Binary Tree - https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> res;
       if(!root)
        return res;
       queue<Node *> q;
       q.push(root);
       while(!q.empty()){
           int count = q.size();
           for(int i = 0; i<count; i++){
               Node *curr = q.front();
               q.pop();
               if(i == count - 1)
                res.push_back(curr->data);
               if(curr->left)
                q.push(curr->left);
               if(curr->right)
                q.push(curr->right);
           }
       }
       return res;
    }
};

/********************************************************************************************************/
// Top View of Binary Tree - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> res;
        if(!root)
            return res;
        queue<pair<Node *, int>> q;
        map<int, int> m;
        q.push({root, 0});
        while(!q.empty()){
            pair<Node *, int> curr = q.front();
            q.pop();
            Node *temp = curr.first;
            int hd = curr.second;
            if(m.find(hd) == m.end()){
                m[hd] = temp->data;
            }
            if(temp->left){
                q.push({temp->left, hd - 1});
            }  
            if(temp->right){
                q.push({temp->right, hd + 1});
            }
        }
        for(auto k:m){
            res.push_back(k.second);
        }
        return res;   
    }
};
/*****************************************************************************************************/
// Bottom View of Binary Tree - https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        if(!root)
            return res;
        queue<pair<Node *, int>> q;
        map<int, int> m;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node *, int> curr = q.front();
            q.pop();
            Node *temp = curr.first;
            int hd = curr.second;
            m[hd] = temp->data;
            if(temp->left){
                q.push({temp->left, hd - 1});
            }  
            if(temp->right){
                q.push({temp->right, hd + 1});
            }
        }
        for(auto k:m){
            res.push_back(k.second);
        }
        return res;
    }
};
/****************************************************************************************************/
// ZigZag Tree Traversal - https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

vector <int> zigZagTraversal(Node* root)
{
	// Code here
	stack<Node *> s1;
	stack<Node *> s2;
	vector<int> res;
	if(!root)
	    return res;
	s1.push(root);
	bool flag = false;
	while(!s1.empty() || !s2.empty()){
	    while(s1.empty() == false){
            Node *curr = s1.top();
            s1.pop();
            if(flag == false){
                if(curr->left)
    	           s2.push(curr->left);
    	        if(curr->right)
    	           s2.push(curr->right);
            }
            else{
                if(curr->right)
    	           s2.push(curr->right);
    	        if(curr->left)
    	           s2.push(curr->left);
            }
            res.push_back(curr->data);
        }
        flag = !flag;
        swap(s1,s2);
	}
}
/***************************************************************************************************************/
// Diagonal Traversal of Binary Tree - https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> res;
   if(!root)
    return res;
   queue<Node *> q;
   q.push(root);
   while(!q.empty()){
       Node *curr = q.front();
       q.pop();
       Node *p = curr;
       while(p){
           if(p->left)
            q.push(p->left);
           res.push_back(p->data);
           p = p->right;
       }
   }
   return res;
}
/*********************************************************************************************************************/
// Boundary Traversal of binary tree - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

class Solution {
public:
    void printLeaves(Node *root, vector<int> &res){
        if(!root)
            return;
        if(root->left == NULL && root->right == NULL)
            res.push_back(root->data);
        if(root->left)
            printLeaves(root->left, res);
        if(root->right)
            printLeaves(root->right, res);
    }
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> res;
        if(!root)
            return res;
        res.push_back(root->data);
        Node *p = root->left;
        while(p){
            if(!p->left && !p->right)
                break;
            res.push_back(p->data);

            if(p->left){
                p = p->left;
            }
            else if(p->right) {
                p = p->right;
            }
        }
        printLeaves(root, res);
        p = root->right;
        stack<int> s;
        while(p){
            if(!p->left && !p->right)
                break;
            s.push(p->data);

            if(p->right){
                p = p ->right;
            }
            else if(p->left) {
                p = p->left;
            }
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};
/***********************************************************************************/
// Transform to Sum Tree - https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *root)
    {
        // Your code here
        if(!root)
            return;
        if(!root->left && !root->right){
            root->data = 0;
            return;
        }
        int l = 0;
        int r = 0;
        if(root->left){
            l = root->left->data;
            toSumTree(root->left);
            l += root->left->data;
        }
        if(root->right){
            r = root->right->data;
            toSumTree(root->right);
            r += root->right->data;
        }
        root->data = l + r;
    }
};
/**************************************************************************************************/
// Leaf at same level - https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

class Solution{
  public:
    int maxHeight(struct Node* root){
        if(!root)
            return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
    int minDepth(Node *root)
    {
        // Corner case. Should never be hit unless the code is
        // called on root = NULL
        if (root == NULL)
            return 0;
     
        // Base case : Leaf Node. This accounts for height = 1.
        if (root->left == NULL && root->right == NULL)
        return 1;
       
        int l = INT_MAX, r = INT_MAX;
        // If left subtree is not NULL, recur for left subtree
       
        if (root->left)
        l = minDepth(root->left);
     
        // If right subtree is not NULL, recur for right subtree
        if (root->right)
        r =  minDepth(root->right);
     
      //height will be minimum of left and right height +1
        return min(l , r) + 1;
    }
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        return maxHeight(root) == minDepth(root);
    }
};
/***************************************************************************************/
// Sum Tree - https://practice.geeksforgeeks.org/problems/sum-tree/1
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         if(!root)
            return true;
         if(!root->left && !root->right)
            return true;
         if(isSumTree(root->left) && isSumTree(root->right)){
             int l = 0;
             int r = 0;
             if(root->left)
                l = root->left->data;
             if(root->right)
                r = root->right->data;
             if(root->data == l+r){
                root->data += l+r;                
                return true;
             }
         }
         return false;
    }
    
};
/********************************************************************************************/
// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)  - https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#
class Solution
{
public:
    void sumRec(Node *root, int len, int sum, int &maxLen, int &maxSum){
        if(!root){
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen && sum>maxSum){
                maxSum = sum;
            }
            return;
        }
        sumRec(root->left, len+1, sum+root->data, maxLen, maxSum);
        sumRec(root->right, len+1, sum+root->data, maxLen, maxSum);

    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(!root)
            return 0;
        int maxSum = INT_MIN;
        int maxLen = 0;
        sumRec(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};
/***************************************************************************************************/
