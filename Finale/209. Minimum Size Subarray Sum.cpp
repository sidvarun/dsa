class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0;
        int r = 0;
        
        int res = INT_MAX;
        int sum = 0;
        
        while(r < nums.size()){

            if(r < nums.size() && sum < target){
                sum += nums[r];
                r++;
            }
            else{
                res = min(res, r - l);
                sum -= nums[l];
                l++;
            }
        }
        
        while(sum >= target){
           res = min(res, r - l);
           sum -= nums[l];
           l++; 
        }
        
        return res == INT_MAX ? 0 : res;
    }
};