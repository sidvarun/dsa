class Solution {
public:
    int n;
    int sideLength;
    vector<int> matches;
    bool dfs(int j, vector<int> sides){
        if(j == n)
            return true;
        for(int k = 0; k<4; k++){
            if(sides[k] + matches[j] <= sideLength){
                sides[k] += matches[j];
                if(dfs(j + 1, sides))
                    return true;
                sides[k] -= matches[j];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto x : matchsticks)
            sum += x;
        sideLength = sum/4;
        if(sum % 4 != 0)
            return false;
        n = matchsticks.size();
        matches = matchsticks;
        sort(matches.begin(), matches.end());
        reverse(matches.begin(), matches.end());

        vector<int> sides(4, 0);
        int j = 0;
        return dfs(0, sides);
    }
};