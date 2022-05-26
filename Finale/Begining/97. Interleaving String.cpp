class Solution {
public:
    int memo[101][101];
    
    bool dp(int i, int j, string s1, string s2, string s3){

        if(i == s1.length() && j == s2.length())
            return true;
//         if(i == s1.length()){
//             string str2 = s2.substr(j);
//             string str3 = s3.substr(i + j);
//             return str2 == str3;
//         }
        
//         if(j == s2.length()){
//             string str1 = s1.substr(i);
//             string str3 = s3.substr(i + j);
//             return str1 == str3;
//         }
        
        if(memo[i][j] != -1)
            return memo[i][j] == 1 ? true : false;
        
        bool choice = false;
        
        if(s1[i] == s3[i + j])
            choice |= dp(i + 1, j, s1, s2, s3);
        
        if(s2[j] == s3[i + j])
            choice |= dp(i, j + 1, s1, s2, s3);
        
        return memo[i][j] = choice;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.length() + s2.length() != s3.length())
            return false;
        
        memset(memo, -1, sizeof(memo));
        
        return dp(0, 0, s1, s2, s3) == 1 ? true : false;
    }
};