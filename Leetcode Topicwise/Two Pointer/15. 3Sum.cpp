https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res; 
        sort(nums.begin(), nums.end());
      
        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum > 0)
                    right--;
                else if(sum < 0)
                    left++;
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(left<right && nums[left] == nums[left-1])
                        left++;
                }
            }
        }
        return res;
    }
};
