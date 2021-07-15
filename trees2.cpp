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
