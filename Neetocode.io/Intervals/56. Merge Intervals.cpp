class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
            
        for(int i = 1; i<intervals.size(); i++){
            vector<int> next = intervals[i];
            if(curr[1] < next[0]){
                res.push_back(curr);
                curr = next;
            }
            else
                curr = vector<int>{min(curr[0], next[0]), max(curr[1], next[1])};
        }
        res.push_back(curr);
        
        return res;
    }
};