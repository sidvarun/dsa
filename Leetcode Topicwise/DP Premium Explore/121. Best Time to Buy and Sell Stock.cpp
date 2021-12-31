class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = INT_MIN;
        int currMin = prices[0];
        
        for(int i = 1; i<prices.size(); i++){
            best = max(best, prices[i] - currMin);
            currMin = min(currMin, prices[i]);
        }
        
        return best >= 0 ? best : 0;
    }
};