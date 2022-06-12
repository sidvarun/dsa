class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0;
        int r = 0;
        
        int freq = nums[r];
        int res = 0;
        
        while(r < nums.size()){
            
            if(r - l + 1 - freq <= k){
                res = max(res, r - l + 1);
                r++;
                if(r < nums.size())
                    freq += nums[r];
            }
            
            else{
                freq -= nums[l];
                l++;
            }
        }
        
        return res;
    }
};