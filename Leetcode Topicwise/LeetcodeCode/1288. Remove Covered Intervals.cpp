class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]) // If two intervals share the same start point, one has to put the longer interval in front.
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int right = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][1] <= right){
                n--;
                continue;
            }
            right = intervals[i][1];
        }
        return n;
    }
};