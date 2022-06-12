class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l = 0;
        int r = 0;
        
        vector<int> freq(26, 0);
        
        freq[s[r] - 'A'] += 1;
        
        int res = 0;
        
        while(r < s.length()){
            
            auto maxmFreq = max_element(freq.begin(), freq.end());
            
            if(r - l + 1 - *maxmFreq <= k){
                res = max(res, r - l + 1);
                r++;
                if(r < s.length())
                    freq[s[r] - 'A']++;
            }
            
            else{
                freq[s[l] - 'A']--;
                l++;
            }
                
        }
        
        return res;
    }
};