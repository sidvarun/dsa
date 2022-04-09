class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        int mid = 0;
        int res = INT_MAX;
        while(l <= r){
            
            
            // if smallest element found
            
            if(nums[l] <= nums[r]){
                res = min(res, nums[l]);   
            }
            
            mid = l + (r - l) / 2;
            
            res = min(res, nums[mid]);
         
            // if in left sorted half
            
            if(nums[mid] >= nums[l])
                l = mid + 1;
                
            // if in right sorted half
                
            else
                r = mid - 1;
        }
        
        return res;
    }
};