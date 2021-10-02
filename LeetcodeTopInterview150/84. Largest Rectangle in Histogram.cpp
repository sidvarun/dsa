https://leetcode.com/problems/largest-rectangle-in-histogram/

Watch this video - https://www.youtube.com/watch?v=zx5Sw9130L0

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = INT_MIN;
        int index = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i<heights.size(); i++){
            if(s.empty() || s.top().second <= heights[i])
                s.push({i, heights[i]});
            else{
                int shift = 0; // here shift is the lowest possible index which can be included int a rectangle of height = heights[i]
                while(!s.empty() && s.top().second > heights[i]){
                    int currHeight = s.top().second;
                    int startIndex = s.top().first;
                    s.pop();
                    int currWidth = i - startIndex;
                    res = max(res, currHeight * currWidth);
                    shift = startIndex;
                }
                s.push({shift, heights[i]});
            }
        }
        int n = heights.size();
        while(!s.empty()){
            res = max(res, s.top().second * (n - s.top().first));
            s.pop();
        }
        return res;
    }
};
