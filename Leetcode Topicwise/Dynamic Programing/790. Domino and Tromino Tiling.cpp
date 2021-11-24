class Solution {
public:
    int numTilings(int n) {
        if(n <= 2)
            return n;
        long long int mod = 1000000007;
        vector<long long> dpFullCover(n + 1, 0);
        vector<long long> dpPartiallyCover(n+1, 0);
        dpFullCover[1] = 1;
        dpFullCover[2] = 2;
        dpPartiallyCover[2] = 1;
        
        for(int i = 3; i<=n; i++){
            dpFullCover[i] = (dpFullCover[i - 1] +  dpFullCover[i - 2] + 2 * dpPartiallyCover[i - 1])%mod;
            dpPartiallyCover[i] = (dpPartiallyCover[i - 1] + dpFullCover[i - 2])%mod;
        }
        return dpFullCover[n];
    }
};