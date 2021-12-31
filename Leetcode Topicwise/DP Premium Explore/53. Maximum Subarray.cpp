class Solution {
public:
    int maxSubArray(vector<int>& nums){
        
        int best = INT_MIN;
        int current = 0;
        
        for(int i = 0; i<nums.size(); i++){
            current = max(current + nums[i], nums[i]);
            best = max(best, current);
        }
        
        return best;
    }
};