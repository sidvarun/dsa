// the point of this algorithm is making use of the previous cached subproblems instead of recalculating the same values. 
// We query what the answer was without the last bit, get that answer in constant time and then add the last set bit before
// marking the current index with the value.


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        int offSet = 1;
        
        for(int i = 1; i <= n; i++){
            if(offSet * 2 == i)
                offSet = i;
            dp[i] = 1 + dp[i - offSet];
        }
        
        return dp;
    }
};