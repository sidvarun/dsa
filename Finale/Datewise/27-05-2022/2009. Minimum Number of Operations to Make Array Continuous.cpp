class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int l = 0;
        int r = 0;
        
        
        int res = 0;
        
        while(r < nums.size()){
            
            if(nums[r] <= nums[l] + n - 1){
                res = max(res, r - l + 1);
                r++;
            }
            
            else
                l++;
        }
        
        return n - res;
        
    }
};