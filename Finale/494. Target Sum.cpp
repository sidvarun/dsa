https://leetcode.com/problems/target-sum/solution/

class Solution {
public:
    // vector<vector<int>> memo;
    int memo[21][100001];
    int total;
    
    int dp(vector<int> &nums, int n, int target){
        
        
        if(n == 0 && target == 0)
            return 1;
        
        if(n == 0)
            return 0;
        
        if(memo[n][target + total] != -1)
            return memo[n][target + total];
        
        int res = dp(nums, n - 1, target - nums[n - 1]) + dp(nums, n - 1, target + nums[n - 1]);
        
        return memo[n][target + total] = res;
        
        
            
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        memset(memo, -1, sizeof(memo));
        
        total = 0;
        
        for(auto num : nums)
            total += num;
        
        total *= 2;
        
        int n = nums.size();
        
        
        return dp(nums, nums.size(), target);
    }
};