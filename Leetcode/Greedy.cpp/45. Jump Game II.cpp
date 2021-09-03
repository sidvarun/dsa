https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, INT_MAX);
    //     dp[n - 1] = 0;
    //     for(int i = n - 2; i >= 0; i--){
    //         for(int j = i + 1; j < n; j++){
    //             if(i + nums[i] >= j && dp[j] != INT_MAX)
    //                 dp[i] = min(dp[i], 1 + dp[j]);
    //         }
    //     }
    //     return dp[0];
    // }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, maxReachable = 0, lastJumped = 0, i = 0;
        while(lastJumped < n - 1){
            maxReachable = max(maxReachable, i + nums[i]);
            if(i == lastJumped){
                lastJumped = maxReachable;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};