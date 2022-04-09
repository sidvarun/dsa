class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int newStart = newInterval[0]; // starting point of the interval to be added
        int newEnd = newInterval[1];   // Ending point of the interval to be added
        
        vector<vector<int>> res;
        for(int i = 0; i<intervals.size(); i++){
            if(newEnd < intervals[i][0]){ // if the interval to be added ends before the start of intervals[i]
                res.push_back(vector<int>{newStart, newEnd});
                res.insert(res.begin() + res.size(), intervals.begin() + i, intervals.end());
                return res;
            }
            
            else if(newStart > intervals[i][1]){ // if interval to be added starts after the end of intervals[i]
                res.push_back(intervals[i]);
            }
            
            else{ // there is and overlap between intervals[i] && iterval [newStart, newEnd]
                
                // In this case merge intervals[i] && interval [newStart, newEnd]
                newStart = min(newStart, intervals[i][0]);
                newEnd = max(newEnd, intervals[i][1]);
            }
        }
        
        res.push_back(vector<int>{newStart, newEnd});
        return res;
    }
};