https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int ans;
        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < target){
                    if(target - sum < res){
                        res = target - sum;
                        ans = sum;
                    }
                    left++;
                    // while(left < right && nums[left] == nums[left - 1])
                    //     left++;
                    // This is done to avoid duplicates as in 3 - Sum Problem but in this question we do not need to take care of the duplicates.
                }
                else if(sum > target){
                    if(sum - target < res){
                        res = sum - target;
                        ans = sum;
                    }
                    right--;
                    // while(left < right && nums[right] == nums[right + 1])
                    //     right--;
                }
                else 
                    return target;
            }
        }
        return ans;
    }
};

