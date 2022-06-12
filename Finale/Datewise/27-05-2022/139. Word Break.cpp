class Solution {
public:
    unordered_set<string> st;
    int memo[300];
    
    bool dp(int i, string s){
        
        if(i == s.length())
            return true;
        
        if(memo[i] != -1)
            return memo[i];
        
        for(int j = i; j<s.length(); j++){
            string str = s.substr(i, j - i + 1);
            if(st.find(str) != st.end() && dp(j + 1, s))
                return true;
        }
        
        return memo[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict)
            st.insert(word);
                
        memset(memo, -1, sizeof(memo));
        
        return dp(0, s);
    }
};