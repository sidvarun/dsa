https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/1181612/Java-Clean-O(N-logN)-Rolling-Hash-Solution-oror-with-comments

#define ull unsigned long long
class Solution {
public:
    
    ull hash;
    ull prime;
    ull mod;
    
    bool solve(int L, vector<int>& nums1, vector<int>& nums2){
        unordered_set<ull> s;
        hash = 0;
        ull power = 1;
        
        for(int i = 1; i < L; i++)
            power = (power * prime) % mod;
        
        for(int i = 0; i < nums1.size(); i++){
            if(i < L){
                hash = hash * prime + (nums1[i] + 1);
                hash = hash % mod;
                continue;
            }
            
            s.insert(hash);
            
            hash = hash - ((nums1[i - L] + 1) * power % mod) + mod;
            
            hash = hash * prime + (nums1[i] + 1);
            
            hash = hash % mod;
        }
        
        s.insert(hash);
        
        hash = 0;
        
        for(int i = 0; i < nums2.size(); i++){
            if(i < L){
                hash = hash * prime + (nums2[i] + 1);
                hash = hash % mod;
                continue;
            }
            
            if(s.find(hash) != s.end())
                return true;
            
            hash = hash - ((nums2[i - L] + 1) * power % mod) + mod;
            
            hash = hash * prime + (nums2[i] + 1);
            
            hash = hash % mod;
            
        }
        
        if(s.find(hash) != s.end())
            return true;
        
        return false;
    }
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        prime = 101;
        mod = 1000000007;
        int n = nums1.size();
        
        int l = 1;
        
        int r = n;
        
        int res = INT_MIN;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            
            bool val = solve(mid, nums1, nums2);
            
            if(val){
                res = mid;
                l = mid + 1;
            }
            
            else
                r = mid - 1;
        }
        
        return res == INT_MIN ? 0 : res;
    }
};