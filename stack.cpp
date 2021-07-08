// balanced parenthesis problem
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ismatch(char a, char b){
        return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
    }
    bool ispar(string x)
    {
        // Your code here
        stack <char> s;
        for(char i:x){
            if(i=='(' || i=='{' || i=='[')
                s.push(i);
            else{
                if(s.empty())
                    return false;
                if(!ismatch(s.top(),i))
                    return false;
                s.pop();
            }
        }
        return s.empty();

    }

};
/*************************************************************/
 // Stock Span Problem
 class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> res;
       stack<int> s;
       res.push_back(1);
       s.push(0);
       for(int i = 1; i<n; i++){
            while(s.empty() == false && price[s.top()] <= price[i])
                s.pop();
            int span = s.empty() ? i+1 : i - s.top();
            res.push_back(span);
            s.push(i);
       }
       return res;
    }
};
/****************************************************************/
// previous Greater Element
#include <bits/stdc++.h>
using namespace std;

void printPrevGreater(int arr[],int n){
    stack<int>s;
    s.push(arr[0]);
    for(int i=0;i<n;i++){
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        int pg=s.empty()?-1:s.top();
        cout<<pg<<" ";
        s.push(arr[i]);
    }
}

int main() 
{ 
    int arr[]={20,30,10,5,15};
    int n=5;
    printPrevGreater(arr,n);
    return 0; 
}
/******************************************************************/
// Next Greater Element
vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        vector<long long> res;
        res.push_back(-1);
        s.push(arr[n-1]);
        for(int i = n-2; i>=0; i--){
            while(s.empty() == false && s.top() <= arr[i])
                s.pop();
            long long next_greater = s.empty()?-1:s.top();
            res.push_back(next_greater);
            s.push(arr[i]);
        }
        reverse(res.begin(), res.begin()+n);
        return res;
    }

// Larges Rectangular area in a Histogram
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> s;
        long long res,curr;
        res = INT_MIN;
        for(int i = 0; i<n; i++){
            while(s.empty() == false && arr[s.top()]>=arr[i]){
                long long tp = s.top();
                s.pop();
                curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                res = max(res,curr);
            }
            s.push(i);
        }
        while(s.empty() == false){
            long long tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
            res = max(res,curr);
        }
        return res;
    }
};
/*******************************************************************************/
// Implemeting a Stack using 2 queues
void QueueStack :: push(int x)
{
        // Your Code
        if(q1.empty()){
            q1.push(x);
            while(q2.empty() == false){
                q1.push(q2.front());
                q2.pop();
            }       
        }
        else{
            q2.push(x);
            while(q1.empty() == false){
                q2.push(q1.front());
                q1.pop();
            }     
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code      
        if(q1.empty() && q2.empty())
            return -1;
        if(q1.empty()){
            int tp = q2.front();
            q2.pop();
            return tp;
        }
        if(q2.empty()){
            int tp = q1.front();
            q1.pop();
            return tp;
        }
}
/************************************************************************************/
// Reverse a queue using Recursion
void revRec(queue<int> &q, queue<int> &q2){
    if(q.empty())
        return;
    int t = q.front();
    q.pop();
    revRec(q,q2);
    q2.push(t);
    
    
}
queue<int> rev(queue<int> q){
    // add code here.
    queue<int> q2;
    revRec(q,q2);
    return q2;
}
/***********************************************************************************/
// Implementing a queue using 2 stacks
//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    // Your Code
    while(s1.empty() == false){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(s2.empty() == false){
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code      
        if(s1.empty())
            return -1;
        int tp = s1.top();
        s1.pop();
        return tp;
}
/***********************************************************************************/
// Sort a stack using Recursion
void insert(stack<int> &s, int tp){
    if(s.empty() || s.top()<=tp){
        s.push(tp);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s,tp);
    s.push(temp);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
    return;
   int tp = s.top();
   s.pop();
   sort();
   insert(s,tp);
}
/***********************************************************************************/
// Reverse the 1st K elements of the queue
queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    queue<int> q2;
    stack<int> s;
    while(q.empty() == false && k>0){
        s.push(q.front());
        q.pop();
        k--;
    }
    while(s.empty()==false){
        q2.push(s.top());
        s.pop();
    }
    while(q.empty()==false){
        q2.push(q.front());
        q.pop();
    }
    return q2;
}
/***********************************************************************************/
// LRU cache (TLE ERROR)
class LRUCache
{

    private :
        map<int,int> mp;
        deque<int> temp;
        int no;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        mp.clear();
        temp.clear();
        no = cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
       if (mp.find(key)==mp.end()) 
            return -1;
      else{
          deque<int> :: iterator itr = temp.begin();
          while (*itr!=key) itr++;
          temp.erase(itr);
          temp.push_front(key);
          return mp[key];
      }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (mp.find(key)==mp.end()){
           if (temp.size()==no){
            int k = temp.back();
            temp.pop_back();
            mp.erase(k); 
           }
       }    
       else {
            deque<int> :: iterator itr = temp.begin();
            while (*itr!=key) itr++;
            temp.erase(itr);
            mp.erase(key);
        }
        temp.push_front(key);
        mp[key] = value;
    }
};
/**********************************************************************************/ 
// First negative integer in every window of size k 
vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
                                                 
    
    vector<long long> res;
    deque<long long> dq;
    for(int i=0; i<k; i++){
        
        if(a[i]<0)
            dq.push_back(a[i]);
    }
    for(int i=k; i<=n; i++){
        if(dq.empty())
            res.push_back(0);
        else{
            res.push_back(dq.front());
        }
        if(i<n && a[i]<0)
            dq.push_back(a[i]);
        if(!dq.empty() && dq.front() == a[i-k])
            dq.pop_front();
        
    }
    return res;
 }
 /***********************************************************************************/
 