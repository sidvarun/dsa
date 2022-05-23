class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums1) {
        int n = nums1.size();
        
        vector<int> res(n, -1);
        
        stack<int> s1;
        
        vector<int> nums = nums1;
        
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        
        for(int i = 2 * n - 1; i >= 0; i--){
            while(!s1.empty() && s1.top() <= nums[i % n])
                s1.pop();
            if(!s1.empty())
                res[i % n] = s1.top();
            s1.push(nums[i % n]);
        }

        return res;
    }
};