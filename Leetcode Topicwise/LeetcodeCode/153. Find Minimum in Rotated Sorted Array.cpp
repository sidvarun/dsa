class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int res = INT_MAX;
        while(l <= r){
            if(nums[r] >= nums[l]){
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2 ;
            res = min(res, nums[mid]);
            if(nums[mid] >= nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return res;
    }
};