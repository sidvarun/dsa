https://leetcode.com/problems/word-search-ii/

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
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = prefix[i]-'a';
            if(parent->children[val]==NULL)
                return false;
            parent = parent->children[val];
        }
        return true;
    }
   
};
class Solution {
public:
    unordered_map<string, int> subres;
    vector<string> res;
    Trie* dict;
    Solution(){
        dict = new Trie();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i = 0; i<words.size(); i++)
            dict->insert(words[i]);
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                string str = "";
                dfs(board, i, j, m, n, str);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n, string str){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] == '{')
            return;
        str += board[i][j];
        if(dict->startsWith(str) == false)
            return;
        if(dict->search(str) && subres.find(str) == subres.end()){
            res.push_back(str);
            subres[str] = 1;
        }
        char temp = board[i][j];
        board[i][j] = '{';
        dfs(board, i + 1, j, m, n, str);
        dfs(board, i - 1, j, m, n, str);
        dfs(board, i, j + 1, m, n, str);
        dfs(board, i, j - 1, m, n, str);
        board[i][j] = temp;
    }
};