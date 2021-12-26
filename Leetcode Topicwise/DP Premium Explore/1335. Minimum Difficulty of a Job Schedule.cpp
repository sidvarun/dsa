class Solution {
public:
    // dp(i, day)
    int memo[300][10];
    int dp(vector<int>& jobs, int i, int day, int d){
        if(day == d){
            int res = INT_MIN;
            for(int k = i; k<jobs.size(); k++)
                res = max(res, jobs[k]);
            return res;
        }
        
        if(memo[i][day] != -1)
            return memo[i][day];
        int remaining = jobs.size() - (d - day);
        int hardest = jobs[i];
        int subres = INT_MAX;
        for(int j = i; j<remaining; j++){
            hardest = max(hardest, jobs[j]);
            int temp = hardest + dp(jobs, j + 1, day + 1, d);
            subres = min(subres, temp);
        }
        
        memo[i][day] = subres;
        return memo[i][day];
    }
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        if(d > n)
            return -1;
        memset(memo, -1, sizeof(memo));
        return dp(jobs, 0, 1, d);
    }
};