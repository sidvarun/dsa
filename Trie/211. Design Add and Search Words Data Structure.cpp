https://leetcode.com/problems/design-add-and-search-words-data-structure/

class TrieNode{
    public:
        vector<TrieNode*> children;
        bool isWord = false;
        TrieNode(){
            children.resize(26, NULL);
        }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* current = root;
        for(char ch:word){
            if(!current->children[ch - 'a']){
                current->children[ch - 'a'] = new TrieNode();
            }
            current = current->children[ch - 'a'];
        }
        current->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, root);
    }
private:
    
    bool searchHelper(string word, TrieNode* current) {
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch != '.'){
                if(!current->children[ch - 'a']) 
                    return false;
                current = current->children[ch - 'a'];
            }
            else{
                for(int j = 0; j < 26; j++){
                    if(current->children[j] && searchHelper(word.substr(i + 1), current->children[j])){
                        return true;
                    }
                }
                return false;
            }
        }
        return current->isWord;
    }
};