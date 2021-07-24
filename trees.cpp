//inorder traversal
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    inorder(root);
}
/***********************************************************************************************/

// preorder traversal
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    preorder(root);
}
/**********************************************************************************************/

// postorder traversal

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    postorder(root);
}
/**********************************************************************************************/

// Height of Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << height(root);
}
/**********************************************************************************************/

// print all nodes at K distance

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void printKDist(Node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->key << " ";
    }
    else
    {
        printKDist(root->left, k - 1);
        printKDist(root->right, k - 1);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);
    int k = 2;

    printKDist(root, k);
}
/********************************************************************************************/

// Lever order travelsal of binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void printLevel(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    printLevel(root);
}
/**************************************************************************************************************************/

// Level order traversal Line by line

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void printLevel(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    printLevel(root);
}

// Method 2 for Level order traversal Line by line

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void printLevel(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << "\n";
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    printLevel(root);
}
/************************************************************************************************************************/

// Size of a Binary tree (number of nodes present in the Binary Tree)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + getSize(root->left) + getSize(root->right);
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);

    cout << getSize(root);
}

/*******************************************************************************************************/

// Node with maximum value in a Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int getMax(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    else
        return max(root->key, max(getMax(root->left), getMax(root->right)));
}

int main()
{

    Node *root = new Node(20);
    root->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << getMax(root);
}

/***************************************************************************************************************************/

// Print left view of a Binary Tree (Method-1 Recursive Approach)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int maxLevel = 0; // global variable to store the maxlevel that has been visited so far
void printLeft(Node *root, int level)
{
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}

void printLeftView(Node *root)
{
    printLeft(root, 1); // passing value of level variable which will store the current level
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    printLeftView(root);
}

// left View Method 2 (Iterative Approach)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void printLeft(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    printLeft(root);
}

/****************************************************************************************************************************/

// Child Sum Property

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

bool isCSum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum += root->left->key;
    if (root->right != NULL)
        sum += root->right->key;

    return (root->key == sum && isCSum(root->left) && isCSum(root->right));
}

int main()
{

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    cout << isCSum(root);
}
/***************************************************************************************************************************/

// Check for a balanced Binary Tree

// Naive Solution
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    cout << isBalanced(root);
}

// Method 2 - O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int isBalanced(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}
/**************************************************************************************************************************/

// Maximum Width of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int maxWidth(Node *root){
    if(root==NULL)return 0;
    queue<Node *>q;
    q.push(root);
    int res=0;
    while(q.empty()==false){
        int count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return res;
}  

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	
	cout<<maxWidth(root);
}
/*****************************************************************************************************************/

// Tree Traversal in spiral form : Method - 1

#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void printSpiral(Node *root){
    if(root==NULL)return;
    queue<Node *>q;
    stack<int> s;
    bool reverse=false;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
        Node *curr=q.front();
        q.pop();
        if(reverse)
            s.push(curr->key);
        else
            cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
        }
        if(reverse){
            while(s.empty()==false){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
    reverse=!reverse;
    }
}  

int main() {
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	printSpiral(root);
}
/***************************************************************************************************************************/

// Method - 2
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void printSpiral(Node *root){
    if (root == NULL) 
        return;  

    stack<Node*> s1;  
    stack<Node*> s2;  
  
    s1.push(root); 
  
    while (!s1.empty() || !s2.empty()) { 
        while (!s1.empty()) { 
            Node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->key << " "; 
  
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left); 
        } 
        
        while (!s2.empty()) { 
            Node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->key << " "; 
  
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
        } 
    } 
}  

int main() {
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	printSpiral(root);
}
/****************************************************************************************************************************/

// Diameter of a Binary Tree 
// Method - 1
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int height(Node *root){
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));
}

int diameter(Node *root){
    if(root==NULL)return 0;
    int d1=1+height(root->left)+height(root->right);
    int d2=diameter(root->left);
    int d3=diameter(root->right);
    
    return max(d1,max(d2,d3));
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(60);
	root->right->left->left=new Node(50);
	root->right->right->right=new Node(70);
	
	cout<<diameter(root);
}
/*******************************************************************************************/

// Method - 2

#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int res=0;
int height(Node *root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    res=max(res,1+lh+rh);
    
        return 1+max(lh,rh);
}


int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(60);
	root->right->left->left=new Node(50);
	root->right->right->right=new Node(70);
	
	cout<<"Height: "<<height(root)<<endl;
	cout<<"Diameter: "<<res;
}
/********************************************************************************************************/

// Lowest common Ancestor  (Efficient Method)
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

Node *lca(Node *root, int n1, int n2){
    if(root==NULL)return NULL;
    if(root->key==n1||root->key==n2)
        return root;
    
    Node *lca1=lca(root->left,n1,n2);
    Node *lca2=lca(root->right,n1,n2);
    
    if(lca1!=NULL && lca2!=NULL)
        return root;
    if(lca1!=NULL)
        return lca1;
    else
        return lca2;
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=20,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
}

// Method - 2 (Naive)
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

bool findPath(Node *root, vector<Node *> &p, int n){
    if(root==NULL)return false;
    p.push_back(root);
    if(root->key==n)return true;
    
    if(findPath(root->left,p,n)||findPath(root->right,p,n))return true;
    
    p.pop_back();
    return false;
}

Node *lca(Node *root, int n1, int n2){
    vector <Node *> path1, path2;
    if(findPath(root,path1,n1)==false||findPath(root,path2,n2)==false)
        return NULL;
    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    return NULL;
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=20,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
}
/******************************************************************************************************************************/

// Burn a Binary Tree from a Leaf Node
int burnTime(Node *root, int leaf, int &dist, int &res){
    if(root==NULL)return 0;
    if(root->data==leaf){dist=0;return 1;}
    int ldist=-1,rdist=-1;
    int lh=burnTime(root->left,leaf,ldist,res);
    int rh=burnTime(root->right,leaf,rdist,res);
    
    if(ldist!=-1){
       dist=ldist+1;
       res=max(res,dist+rh);
    }
    else if(rdist!=-1){
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    return max(lh,rh)+1;
}
int minTime(Node* root, int n) 
{
    int dist, res;
    res = 0;
    burnTime(root, n, dist, res);
    return res;
}

/******************************************************************/

// Mirror Tree
lass Solution{
    public:
    //Function to convert a binary tree into its mirror tree.
    void mirror(Node* root)
    {
     // code here
         if(root == NULL)
          return;
         mirror(root->right);
         mirror(root->left);
         Node *temp;
         if(root->right && root->left){
            temp = root->right;
            root->right = root->left;
            root->left = temp;
         }
         else if(root->right){
            root->left = root->right;
            root->right = NULL;
        }
        else
        {
            root->right = root->left;
            root->left = NULL;
        }
    }
    /*******************************************************************/
    // Check if 2 trees are mirror image of each other
    class Solution {
    public:
        int checkMirrorTree(int n, int e, int A[], int B[]) {
            map<int,stack<int>> mp;
            for(int i = 0 ; i < 2*e ; i+=2 )
                mp[A[i]].push(A[i+1]);
            for(int i = 0 ; i < 2*e ; i+=2){
                if(mp[B[i]].top() != B[i+1]) 
                    return 0;
                mp[B[i]].pop();
            }
            return 1;
        }
    };


/*********************/
// 	while(!s1.empty() || !s2.empty()){
// 	    if(s2.empty()){
// 	        while(!s1.empty()){
// 	            Node *curr = s1.top();
// 	            s1.pop();
// 	            if(curr->left){
// 	                s2.push(curr->left);
// 	            }
// 	            if(curr->right){
// 	                s2.push(curr->right);
// 	            }
// 	            res.push_back(curr->data);
// 	        }
// 	    }
// 	    else if(s1.empty()){
// 	        while(!s2.empty()){
// 	            Node *curr = s2.top();
// 	            s2.pop();
// 	            if(curr->left){
// 	                s1.push(curr->left);
// 	            }
// 	            if(curr->right){
// 	                s1.push(curr->right);
// 	            }
// 	            res.push_back(curr->data);
// 	        }
// 	    }
// 	}
// 	return res;
/************************************************/
class Solution {
  public:
    int height(Node *root){
        if (root == NULL)
            return 0;
        else
            return (1 + max(height(root->left), height(root->right)));
    }
    int solve(Node* root, int &res){
        if(!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        int temp = 1 + lh + rh;
        solve(root->left, res);
        solve(root->right, res);
        res = max(res, temp);
        return res;
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int res = INT_MIN;
        int t = solve(root, res);
        return res;
    }
};
/****************************************************/