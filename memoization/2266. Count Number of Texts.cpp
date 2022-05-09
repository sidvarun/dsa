https://leetcode.com/problems/count-number-of-texts/discuss/2019195/Easy-Memoization-or-O(n)-time-or-C%2B%2B-or-With-Explanation

class Solution {
public:
    string s;
    int n;
    int memo[100000];
    int mod;
    
    int dfs(int i){
        if(i == n)
            return 1;
        
        if(memo[i] != -1)
            return memo[i];
        
        int num = 3;
        
        if(s[i] == '7' || s[i] == '9')
            num = 4;
        
        int res = 0;
        
        for(int j = i; j < i + num && j < n; j++){
            if(s[i] == s[j])
                res = (res + dfs(j + 1)) % mod;
            else 
                break;
        }
        
        return memo[i] = res;
    }
    
    int countTexts(string pressedKeys) {
        s = pressedKeys;
        mod = 1000000007;
        n = pressedKeys.length();
        memset(memo, -1, sizeof(memo));
        return dfs(0);
    }
};