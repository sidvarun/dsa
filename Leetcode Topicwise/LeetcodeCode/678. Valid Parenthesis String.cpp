class Solution {
public:
    int memo[100][100];
    int check(string s, int i, int left){
        if(left < 0)
            return false;
        if(i == s.length() && left == 0)
            return true;
        if(i == s.length())
            return false;
        if(memo[i][left] != -1)
            return memo[i][left];
        if(s[i] == '(')
            return memo[i][left] = check(s, i + 1, left + 1);
        if(s[i] == ')')
            return memo[i][left] = check(s, i + 1, left - 1);
        return memo[i][left] = (check(s, i + 1, left) || check(s, i + 1, left + 1) || check(s, i + 1, left - 1));
    }
    bool checkValidString(string s) {
        memset(memo, -1, sizeof(memo));
        return check(s, 0, 0);
    }
};