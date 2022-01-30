class Solution {
public:
    int countSubstrings(string s) {
        int l = 0;
        int r = 0;
        int res = 0;
        
        for(int i = 0; i<s.length(); i++){
        
            // ODD length palindromes
            l = r = i;
            int subres = 0;
            while(l >= 0 && r < s.length()){
                if(s[l] == s[r]){
                    r++;
                    l--;
                    subres++;
                }
                else
                    break;
            }
            res += subres;
        
            // EVEN length palindromes
            subres = 0;
            l = i;
            r = i + 1;
            while(l >= 0 && r < s.length()){
                if(s[l] == s[r]){
                    r++;
                    l--;
                    subres++;
                }
                else
                    break;
            }
            res += subres;
        }
            return res;
    }
};