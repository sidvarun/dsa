class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int cnt[201] = {}, hash[201] = {}, res = 0;
        for (int sz = 0; sz < nums.size(); ++sz) {
            unordered_set<int> s;
            for (int i = 0; i + sz < nums.size(); ++i) {
                cnt[i] += nums[i + sz] % p == 0;
                if (cnt[i] <= k) {
                    hash[i] = ((long long)hash[i] * 200 + nums[i + sz]) % 1000000007;
                    res += s.insert(hash[i]).second;
                }
            }
        }
        return res;
    }
};

/***********************************************************************************************************/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        long mod = INT_MAX;
        int n = nums.size();

        unordered_set<long> s;
        
        for(int i = 0; i<n; i++){
            
            long h = 0;
            int count = 0;
            for(int j = i; j<n; j++){
                
                if(nums[j] % p == 0)
                    count++;
                
                if(count > k)
                    break;
                
                h = ((h * 201) + nums[j]) % mod;
                
                s.insert(h);
            }
        }
        return s.size();
    }
};