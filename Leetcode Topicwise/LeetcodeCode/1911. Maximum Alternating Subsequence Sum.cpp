class Solution {
public:
    long long memo[100000][2];
    int n;
    long long dfs(int i, int state, vector<int>& nums){
        if(i == n)
            return 0;
        if(memo[i][state] != -1)
            return memo[i][state];
        long long subres = 0;
        if(state == 0)
            subres = nums[i] + dfs(i + 1, 1, nums);
        else if(state == 1)
            subres = -1 * nums[i] + dfs(i + 1, 0, nums);
        return memo[i][state] = max(dfs(i + 1, state, nums), subres);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i<100000; i++){
            memo[i][0] = -1;
            memo[i][1] = -1;
        }
        n = nums.size();
        return dfs(0, 0, nums);
    }
};