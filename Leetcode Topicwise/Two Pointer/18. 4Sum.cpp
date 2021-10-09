https://leetcode.com/problems/4sum/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j<n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    long long int sum = (long long int)nums[i] + (long long int)nums[j] + (long long int)nums[left] + (long long int)nums[right];
                    if(sum < target)
                        left++;
                    else if(sum > target)
                        right--;
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                        right--;
                        while(left < right && nums[right] == nums[right+1])
                            right--;
                    }
                }
            }
        }
        return res;
    }
};
