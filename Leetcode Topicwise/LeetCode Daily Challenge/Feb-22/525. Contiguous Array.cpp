class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        
        int sum = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0)
                sum -= 1;
            else 
                sum += 1;
            
            if(sum == 0){
                res = max(res, i + 1);
                continue;
            }
            if(m.find(sum) != m.end())
                res = max(res, i - m[sum]);
            else
                m[sum] = i;
        }
        return res;
    }
};