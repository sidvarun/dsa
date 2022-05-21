https://leetcode.com/problems/132-pattern/discuss/2044567/C%2B%2B-Intuitive-Solution-with-stack-or-Explained

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<pair<int, int>> s; // {nums[i], minElement to the left of nums[i]}
        
        int minm = nums[0];
                
        int n = nums.size();

        
        // loop starting from i = 1 because k cannot be 0
        for(int i = 1; i < n; i++){
            
            while(!s.empty() && s.top().first <= nums[i])
                s.pop();

            if(!s.empty() && s.top().second < nums[i])
                return true;
            
            minm = min(minm, nums[i]);
            s.push({nums[i], minm});
        }
        
        return false;
        
    }
};