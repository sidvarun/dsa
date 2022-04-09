class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        for(int i = 1; i<intervals.size(); i++){
            int currStart = intervals[i][0];
            int prevEnd = intervals[i - 1][1];
            
            if(prevEnd > currStart)
                return false;
        }
        
        return true;
    }
};