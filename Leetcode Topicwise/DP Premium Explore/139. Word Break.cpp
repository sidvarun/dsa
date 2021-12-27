class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        int n = s.length();
        vector<bool> dp(n, false);        
        for(int i = 0; i < n; i++){
            for(string word : wordDict){
                if(i >= word.length() - 1 && (i == word.length() - 1 || dp[i - word.length()])){
                    string str = s.substr(i - word.length() + 1, word.length());
                    if(str == word){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};