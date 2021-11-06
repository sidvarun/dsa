https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[0] < v2[0];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<int> dp(n, 0);
        vector<vector<int>> jobs(n);
        for(int i = 0; i<n; i++){
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), cmp);
        sort(startTime.begin(), startTime.end());
        dp[n - 1] = jobs[n - 1][2];
        for(int i = n - 2; i >= 0; i--){
            int nextJobIndex = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
            dp[i] = jobs[i][2];
            if(nextJobIndex < n)
                dp[i] += dp[nextJobIndex];
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    } 
};
