class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> nextSmaller(n, -1);
        vector<int> prevSmaller(n, -1);
        
        stack<int> s1;
        
        for(int i = n - 1; i >= 0; i--){
            while(!s1.empty() && heights[s1.top()] >= heights[i])
                s1.pop();
            
            if(!s1.empty())
                nextSmaller[i] = s1.top();
            
            s1.push(i);
        }
        
        stack<int> s2;
        
        for(int i = 0; i < n; i++){
            while(!s2.empty() && heights[s2.top()] >= heights[i])
                s2.pop();
            
            if(!s2.empty())
                prevSmaller[i] = s2.top();
            
            s2.push(i);
        }
        
        int res = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            int right = nextSmaller[i] == -1 ? n : nextSmaller[i];
            int left = prevSmaller[i];
            
            int l = right - left - 1;
            
            int b = heights[i];
            
            int subres = l * b;
            
            res = max(res, subres);
            
        }
        
        return res;
    }
};