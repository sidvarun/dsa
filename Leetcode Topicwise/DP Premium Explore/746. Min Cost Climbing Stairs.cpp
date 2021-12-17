class Solution {
public:
    unordered_map<int, int> memo;
    int rec(vector<int> &cost, int n){
        if(n <= 1)
            return 0;
        if(memo.find(n) == memo.end()){
            memo[n] = min(rec(cost, n - 1) + cost[n - 1], rec(cost, n - 2) + cost[n - 2]);
        }
        return memo[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return rec(cost, n);
    }
};