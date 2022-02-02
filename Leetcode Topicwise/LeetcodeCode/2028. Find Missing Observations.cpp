class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(auto x : rolls)
            sum += x;
        
        int nTotal = mean * (m + n) - sum;
        
        if(nTotal < n || nTotal > 6 * n)
            return vector<int>{};
        
        vector<int> res;
        
        while(nTotal > 0){
            // Be greedy and choose the maximum possible value for the current dice
            int curr = min(6, nTotal - n + 1);
            res.push_back(curr);
            nTotal -= curr;
            n--;
        }
        return res;
    }
};