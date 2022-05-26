class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        
        int res = 0;
        
        for(auto row : wall){
            int total = 0;
            for(int i = 0; i<row.size() - 1; i++){
                int brick = row[i];
                total += brick;
                if(m.find(total) == m.end())
                    m[total] = 1;
                else
                    m[total]++;
                res = max(res, m[total]);
            }
        }
        
        return wall.size() - res;
    }
};