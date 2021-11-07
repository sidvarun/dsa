https://leetcode.com/problems/meeting-rooms-ii/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> startTime;
        vector<int> endTime;
        int n = intervals.size();
        for(int i = 0; i<intervals.size(); i++){
            startTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int res = 0;
        int curr = 0;
        int currTime = endTime[0];
        int i = 0;
        int j = 0;
        while(i < n){
            currTime = endTime[j];
            if(startTime[i] < currTime){
                curr++;
                i++;
            }
            else{
                curr--;
                j++;
            }
            res = max(res, curr);
        }
        return res;
    }
};
