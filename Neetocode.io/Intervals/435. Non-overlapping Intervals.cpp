class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int res = 0;
        
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
    
        for(int i = 1; i < intervals.size(); i++){
            
            int currStart = intervals[i][0];
            
            if(prevEnd > currStart){
                res++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            
            else
                prevEnd = intervals[i][1];
        }
        
        return res;
    }
};