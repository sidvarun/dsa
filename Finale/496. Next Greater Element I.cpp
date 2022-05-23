class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s; // maintain a monotonically decreasing stack
        
        for(int i = 0; i<nums1.size(); i++)
            m[nums1[i]] = i;
        
        int n1 = nums1.size();
        
        vector<int> res(n1, -1);
        
        int n = nums2.size();
        
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && s.top() <= nums2[i])
                s.pop();
            
            if(!s.empty() && m.find(nums2[i]) != m.end()){
                int index = m[nums2[i]];
                res[index] = s.top();
            }
            
            s.push(nums2[i]);
        }
        
        return res;
    }
};