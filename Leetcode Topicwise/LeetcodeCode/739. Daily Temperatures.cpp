class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n);
        stack<int> s;
        s.push(0);
        for(int i = 1; i<temp.size(); i++){
            while(!s.empty() && temp[i] > temp[s.top()]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};