https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0; int right = 0;
        int sum = nums[0];
        int res = INT_MAX;
        while(left <= right && right < n){
            if(sum < target){
                right++;
                if(right < n)
                    sum += nums[right];
            }
            else{
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};