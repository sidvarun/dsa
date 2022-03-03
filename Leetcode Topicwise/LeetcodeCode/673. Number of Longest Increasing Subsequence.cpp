class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n); // <lisLength, count>
        // dp[n - 1] = {1, 1};
        int ans = 0;
        int res = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            int len = 1;
            int count = 1;
            for(int j = i + 1; j < n; j++){
                if(nums[j] > nums[i] && dp[j][0] + 1 > len){
                    len = dp[j][0] + 1;
                    count = dp[j][1];
                    dp[i] = {len, count};
                }
                else if(nums[j] > nums[i] && dp[j][0] + 1 == len){
                    count = dp[i][1] + dp[j][1];
                    dp[i] = {len, count};
                }
            }
            dp[i] = {len, count};
            if(res < dp[i][0]){
                res = dp[i][0];
                ans = dp[i][1];
            }
            else if(res == dp[i][0]){
                ans += dp[i][1];
            }
        }
        return ans;
    }
};

/********************************************************/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n); // <lisLength, count>
        // dp[n - 1] = {1, 1};
        int res = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            int len = 1;
            int count = 1;
            for(int j = i + 1; j < n; j++){
                if(nums[j] > nums[i] && dp[j][0] + 1 > len){
                    len = dp[j][0] + 1;
                    count = dp[j][1];
                    dp[i] = {len, count};
                }
                else if(nums[j] > nums[i] && dp[j][0] + 1 == len){
                    count = dp[i][1] + dp[j][1];
                    dp[i] = {len, count};
                }
            }
            dp[i] = {len, count};
            res = max(res, dp[i][0]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++)
            if(dp[i][0] == res)
                ans += dp[i][1];
        return ans;
    }
};
/*********************************************************************/