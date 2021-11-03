https://leetcode.com/problems/interval-list-intersections/

https://leetcode.com/problems/interval-list-intersections/discuss/647482/Python-Two-Pointer-Approach-%2B-Thinking-Process-Diagrams

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        vector<vector<int>> res;
        
        int i = 0;
        int j = 0;
        
        int l1 = first.size();
        int l2 = second.size();
        
        while(i < l1 & j < l2){
            int left = max(first[i][0], second[j][0]);
            int right = min(first[i][1], second[j][1]);

            if(left <= right)
                res.push_back({left, right});
            
            if(first[i][1] < second[j][1])
                i++;
            else
                j++;
        } 
        return res;
    }
};
