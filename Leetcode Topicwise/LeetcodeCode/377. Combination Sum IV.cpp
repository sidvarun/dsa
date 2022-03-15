class Solution {
public:
    int memo[1000];
    int combination(vector<int> &nums, int target){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(memo[target] != -1)
            return memo[target];
        
        int subres = 0;
        for(int i = 0; i<nums.size(); i++){
            subres += combination(nums, target - nums[i]);
        }
        return memo[target] = subres;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(memo, -1, sizeof(memo));
        return combination(nums, target);
    }
};