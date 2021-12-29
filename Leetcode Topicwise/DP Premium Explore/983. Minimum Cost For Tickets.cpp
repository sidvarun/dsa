class Solution {
public:
    int memo[365][365];
    int dp(int i, int lastDay, vector<int>& days, vector<int>& costs){
        if(i == days.size())
            return 0;
        if(days[i] <= lastDay)
            return dp(i + 1, lastDay, days, costs);
        if(memo[i][lastDay] != INT_MAX)
            return memo[i][lastDay];
        int res = INT_MAX;
        res = min(costs[0] + dp(i + 1, days[i], days, costs), min(costs[1] + dp(i + 1, days[i] + 6, days, costs), costs[2] + dp(i + 1, days[i] + 29, days, costs)));
        memo[i][lastDay] = res;
        return memo[i][lastDay];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i = 0; i<365; i++)
            for(int j = 0; j<365; j++)
                memo[i][j] = INT_MAX;
        return dp(0, 0, days, costs);
    }
};