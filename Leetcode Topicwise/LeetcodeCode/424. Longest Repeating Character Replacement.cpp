class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> m;
        
        for(auto c : s)
            m[c] = 0;
        
        int l = 0;
        int r = 0;
        
        int res = INT_MIN;
        int maxFreq = INT_MIN;
        
        for(int r = 0; r < s.length(); r++){
            m[s[r]]++;
            
            maxFreq = max(maxFreq, m[s[r]]);
            
            while((r - l + 1) - maxFreq > k){
                m[s[l]]--;
                l++;
            }            
            res = max(res, r - l + 1);
        }
        return res;
    }
};