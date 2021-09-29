https://leetcode.com/problems/word-break/

// 35/45 test cases pased, giving TLE for rest

class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode()
        {
            isEnd = false;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
        }
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        int n = word.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = word[i]-'a';
            if(parent->children[val]==NULL)
            {
                parent->children[val] = new TrieNode();
            }
            parent = parent->children[val];
        }
        parent->isEnd = true;
    }
    bool search(string word) {
        int n = word.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = word[i]-'a';
            if(parent->children[val]==NULL)
                return false;
            parent = parent->children[val];
        }
        return parent->isEnd;
    }
};
class Solution {
public:
    map<string, bool> dp;
    Trie* dict;
    Solution(){
        dict = new Trie();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i<wordDict.size(); i++)
            dict->insert(wordDict[i]);
        return helper(0, s, s.length());
    }
    bool helper(int index, string s, int n){
        if(index == n)
            return dict->search(s);
        if(!dict->search(s.substr(0, index + 1)))
            return helper(index + 1, s, n);
        else if(helper(0, s.substr(index + 1, n), s.substr(index + 1, n).length()))
            return true;
        return helper(index + 1, s, n);
    }
};