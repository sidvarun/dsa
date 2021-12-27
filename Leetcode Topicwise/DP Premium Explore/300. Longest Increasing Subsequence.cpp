class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int maxm = 1;
            int j;
            for(j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    maxm = max(maxm, 1 + dp[j]);
            }
            dp[j] = maxm;
            res = max(res, dp[j]);
        }
        return res;
    }
};