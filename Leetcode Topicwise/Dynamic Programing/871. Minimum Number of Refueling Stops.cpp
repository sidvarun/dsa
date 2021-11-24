class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        vector<long> dp(s.size() + 1, INT_MIN);
        dp[0] = startFuel;
        for (int i = 0; i < s.size(); ++i)
            for (int t = i; t >= 0 && dp[t] >= s[i][0]; --t)
                dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1]);
        for (int t = 0; t <= s.size(); ++t)
            if (dp[t] >= target) return t;
        return -1;
    }
};
