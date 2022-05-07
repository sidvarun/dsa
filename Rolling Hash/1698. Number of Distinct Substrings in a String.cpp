#define ull unsigned long long 
class Solution {
public:
    ull prime;
    ull mod;
    
    int solve(int L, string &s){
        
        ull power = 1;
        
        for(int i = 1; i < L; i++)
            power = (power * prime) % mod;
        
        unordered_set<ull> st;
        
        ull hash = 0;
        
        for(int i = 0; i<L; i++){
            hash = hash * prime + (s[i] - 'a');
            hash = hash % mod;
        }
        
        st.insert(hash);
        
        for(int i = L; i<s.length(); i++){
            
            hash = hash - ((s[i - L] - 'a') * power % mod) + mod;
            hash = hash % mod;
                        
            hash = hash * prime + (s[i] - 'a');
            hash = hash % mod;
            
            st.insert(hash);
            
        }
        
        return st.size();
    }
    
    int countDistinct(string s) {
        
        prime = 26;
        mod = 1000000007;
        
        int res = 0;
        
        for(int i = 1; i<=s.length(); i++)
            res += solve(i, s);
        
        return res;
    }
};