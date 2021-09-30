https://practice.geeksforgeeks.org/problems/a512e4b2e812b6df2159b19cc7090ffc1ab056dd/1/?category[]=Trie&category[]=Trie&problemStatus=unsolved&page=1&sortBy=accuracy&query=category[]TrieproblemStatusunsolvedpage1sortByaccuracycategory[]Trie#

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

struct trie{
    trie* next[2];
    trie()
    {
        next[0]=NULL;
        next[1]=NULL;
    }
};
class TrieNode{
    private:
        trie* root;
    public:
        TrieNode()
        {
            root=new trie();
        }
    
    void insert(int num)
    {
        trie* curr=root;
        
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(curr->next[bit]==NULL)
            {
                curr->next[bit]=new trie();
            }
            curr=curr->next[bit];
        }
    }
    
    int max_xor(int num)
    {
        trie* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            
            if(curr->next[!bit])
            {
                ans+=(1<<i);
                curr=curr->next[!bit];
            }
            else
            {
                curr=curr->next[bit];
            }
        }
        return ans;
    }   
};

class Solution{   
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ans=0;
        int n=nums.size();
        
        TrieNode* t=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            t->insert(nums[i]);
            max_ans=max(max_ans,max(nums[i], t->max_xor(nums[i])));
        }
        return max_ans;
    }
    int maxSubarrayXOR(int N, int arr[]){    
        //code here
        vector<int> nums(N);
        nums[0] = arr[0];
        for(int i = 1; i<N; i++){
            nums[i] = arr[i] ^ nums[i - 1];
        }
        return findMaximumXOR(nums);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends