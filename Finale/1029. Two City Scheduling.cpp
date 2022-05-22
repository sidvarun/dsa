
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<vector<int>> diff;
        
        int n = costs.size();
        
        for(int i = 0; i < n; i++){
            
            int d = costs[i][1] - costs[i][0];
            
            diff.push_back(vector<int>{d, i});
        }
        
        sort(diff.begin(), diff.end());
        
        int res = 0;
        
        int c1 = n / 2;
        int c2 = n / 2;
        
        for(int i = 0; i < n; i++){
            if(c2 > 0){
                res += costs[diff[i][1]][1];
                c2--;
            }
            else
                res += costs[diff[i][1]][0];
        }
        
        return res;
    }
};