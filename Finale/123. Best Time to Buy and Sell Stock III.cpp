class Solution {
public:
    int memo[100001][3][2];
    int n;
    int dp(int i, int j, int k, vector<int> &prices){
        
        if(memo[i][j][k] != -1)
            return memo[i][j][k];
        
        if(k == 0){
            if(j == 0)
                return 0;
            if(i >= n)
                return 0;
            
            int choice1 = dp(i + 1, j - 1, 1, prices) - prices[i];
            int choice2 = dp(i + 1, j, 0, prices);
            return memo[i][j][k] = max(choice1, choice2);
        }
        
        if(k == 1){
            if(i == n)
                return prices[n - 1];
            
            int choice1 = dp(i + 1, j, 0, prices) + prices[i];
            int choice2 = dp(i + 1, j, 1, prices);
                
            return memo[i][j][k] = max(choice1, choice2);
        }
        
        return memo[i][j][k];
    }
    
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        n = prices.size();
        return dp(0, 2, 0, prices);
    }
};