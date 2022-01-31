class Solution {
public:
    int maxProduct(string s) {
        unordered_map<int, int> pali;
        int n = s.length();
        
        int range = 1 << n;
        
        for(int mask = 1; mask < range; mask++){
            string subseq = "";
            
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    subseq += s[i];
                }
            }
            string rev = subseq;
            reverse(subseq.begin(), subseq.end());
            if(subseq == rev)
                pali[mask] = subseq.length();
        }
        
        int res = 0;
        for(auto i : pali){
            for(auto j : pali){
                if((i.first & j.first) == 0)
                    res = max(res, pali[i.first] * pali[j.first]);
            }
        }
        return res;
    }
};