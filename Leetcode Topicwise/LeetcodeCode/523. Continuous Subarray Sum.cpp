
// Efficient approach with some clever prefix sum & hashmap
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        unordered_map<int, int>m;
        m[prefix[0] % k] = 0;
        for(int i = 1; i<n; i++){
            prefix[i] = nums[i] + prefix[i - 1];
            
            if(i != 0 && prefix[i] % k == 0)
                return true;
            if(m.find(prefix[i] % k) != m.end() && i - m[prefix[i] % k] >= 2)
                return true;
            if(m.find(prefix[i] % k) == m.end())
                m[prefix[i] % k] = i; 
        }
        return false;
    }
};
/************************************************************/
// TLE : 94/95 cases passed 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> prefix(n, 0);
        
        prefix[0] = nums[0];
        
        for(int i = 1; i<nums.size(); i++)
            prefix[i] = nums[i] + prefix[i - 1];
        
        for(int i = 0; i<n; i++){
            for(int j = i + 1; j<n; j++){
                if(prefix[j] % k == 0)
                    return true;
                if(i != 0 && (prefix[j] - prefix[i - 1]) % k == 0)
                    return true;
            }
        }
        return false;
    }
};