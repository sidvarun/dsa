https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/

// Accepted code from Discuss Section
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
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ans=0;
        int n=nums.size();
        
        TrieNode* t=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            t->insert(nums[i]);
            max_ans=max(max_ans,t->max_xor(nums[i]));
        }
        return max_ans;
    }
};

// My code (Giving TLE but 41/41 passed)
class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[2];
        TrieNode()
        {
            isEnd = false;
            for(int i=0; i<2; i++)
            {
                children[i] = NULL;
            }
        }
};
class Solution {
public:
    int ans;
    TrieNode* root;
    Solution(){
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        int n = word.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = word[i]-'0';
            if(parent->children[val]==NULL)
            {
                parent->children[val] = new TrieNode();
            }
            parent = parent->children[val];
        }
        parent->isEnd = true;
    }
    string decToBin(int dec){
        string bin32  = "00000000000000000000000000000000";
        for (int pos = 31; pos >= 0; --pos)
        {
            if (dec % 2) 
                bin32[pos] = '1';
            dec /= 2;
        }
        return bin32;
    }
    string xoring(string a, string b, int n){
        string ans = "";
        // Loop to iterate over the
        // Binary Strings
        for (int i = 0; i < n; i++)
        {
            // If the Character matches
            if (a[i] == b[i])
                ans += "0";
            else
                ans += "1";
        }
        return ans;
    }
    int stringToint(string binaryString){
        int value = 0;
        int indexCounter = 0;
        for(int i=binaryString.length()-1;i>=0;i--){

            if(binaryString[i]=='1'){
                value += pow(2, indexCounter);
            }
            indexCounter++;
        }
        return value;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        ans = INT_MIN;
        // for(int i = 0; i<nums.size(); i++)
        //     insert(decToBin(nums[i]));
        insert(decToBin(nums[0]));
        for(int i = 1; i<nums.size(); i++){
            string str = decToBin(nums[i]);
            string s = "";
            TrieNode* parent = root;
            for(int j = 0; j<str.length(); j++){
                int val = str[j] - '0';
                if(parent->children[!val] != NULL){
                    parent = parent->children[!val];
                    s += to_string(!val);
                }
                else{
                    parent = parent->children[val];
                    s += to_string(val);
                }
            }
            int subres = stringToint(xoring(str, s, 32));
            ans = max(subres, ans);
            insert(decToBin(nums[i]));
        }
        return ans;
    }
};