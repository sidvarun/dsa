// Check if a binary tree is a BST
class Solution
{
    public:
    bool isBSTrec(Node* root, int min, int max) 
    {   
            // Your code here
        if(root == NULL)
            return true;
        if(root->data < min || root->data > max)
            return false;
        return isBSTrec(root->left, min, root->data - 1) && isBSTrec(root->right, root->data+1, max);
            
    }
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return isBSTrec(root,INT_MIN,INT_MAX);
        
        
    }
};
/*********************************************************************/
//find the minimum element in the given BST.
int minValue(Node* root)
{
    // Code here
    if(root->left == NULL)
        return root->data;
    return minValue(root->left);
}
/********************************************************************/
// LCA in a BST
Node* LCArec(Node *root, int n1, int n2)
{
   //Your code here
   if(root == NULL)
      return root;
   if(root->data == n1 || root->data == n2)
      return root;
   if((root->data > n1 && root->data < n2) || (root->data < n1 && root->data > n2))
      return root;
   if(root->data > n1 && root->data > n2)
      return LCArec(root->left,n1,n2);
   return LCArec(root->right,n1,n2);
   
}
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   return LCArec(root,n1,n2);
   
}
/*********************************************************************/
// Kth Largest Element in a BST
class Solution
{
    public:
    void kthInOrder(Node *root, int k, int &c, int &ans){
           
            if(root == NULL || c >=k)
                return;
            kthInOrder(root->right, k, c, ans);
            c++;
            if(c==k){
             ans = root->data;
             return;
            }
            kthInOrder(root->left, k, c, ans);
        
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        // int num = countNodes(root);
        int c = 0;
        int ans = 0;
        kthInOrder(root, K, c, ans);
        return ans;
    }
};
/**********************************************************************/
// Kth Smallest Element in a BST
class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    void kthInOrder(Node *root, int k, int &c, int &ans){
           
            if(root == NULL || c >=k)
                return;
            kthInOrder(root->left, k, c, ans);
            c++;
            if(c==k){
             ans = root->data;
             return;
            }
            kthInOrder(root->right, k, c, ans);
        
    }
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        int c = 0;
        int ans = -1;
        kthInOrder(root, K, c, ans);
        return ans;
    }
};
/***********************************************************************/
//Brothers from different roots
//https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1#
bool find(Node *root, int key){
    if(root == NULL)
        return false;
    if(root->data == key)
        return true;
    if(root->data < key)
        return find(root->right,key);
    return find(root->left,key);
}
int countPairs1(Node* root1, Node* root2, int x){
    if(root1 == NULL || root2 == NULL)
        return 0;
    if(find(root2,x-root1->data))
        return 1+countPairs1(root1->left,root2,x) + countPairs1(root1->right,root2,x);
    return countPairs1(root1->left,root2,x) + countPairs1(root1->right,root2,x);
}
int countPairs(Node* root1, Node* root2, int x)
{   
    // Code here
    return countPairs1(root1,root2,x);
}
/*****************************************************************************/
//Count BST nodes that lie in a given range 
int getCount(Node *root, int l, int h)
{
  // your code goes here   
  if(root == NULL)
    return 0;
  if(root->data >=l && root->data<=h)
    return 1+getCount(root->left,l,h)+getCount(root->right,l,h);
  return getCount(root->left,l,h)+getCount(root->right,l,h);
}
/*************************************************************************************/
// Find the Inorder predecessor and Inorder successor for a give Key
void findPreSucRec(Node* root, Node*& pre, Node*& suc, int k){
    if(root == NULL)
        return;
    if(root->key < k){
        pre = root;
        findPreSucRec(root->right, pre, suc, k);
    }
    else if(root->key > k){
        suc = root;
        findPreSucRec(root->left, pre, suc, k);
    }
    else{
        findPreSucRec(root->left, pre, suc, k);
        findPreSucRec(root->right, pre, suc, k);
    }
}
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    findPreSucRec(root, pre, suc, key);
}
/**********************************************************************************************/

// Find if a Given BST has a Dead End
bool isDeadUtil(Node *root, int min, int max){
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL){
        if(root->data - min == 1 && max - root->data == 1)
            return true;
        // return false;
    }
    return isDeadUtil(root->left, min, root->data) || isDeadUtil(root->right, root->data, max);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return isDeadUtil(root, 0, INT_MAX);
}
/**********************************************************************************************/
