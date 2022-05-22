class Solution {
public:
    
    void dfs(int i, int j, vector<char>& s){
        
        if(i >= j)
            return;
        
        swap(s[i], s[j]);
        
        dfs(i + 1, j - 1, s);
    
    }
    
    void reverseString(vector<char>& s) {
        dfs(0, s.size() - 1, s);
    }
};