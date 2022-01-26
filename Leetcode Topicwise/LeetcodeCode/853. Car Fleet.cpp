class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> cars;
        int n = speed.size();
        
        for(int i = 0; i<n; i++)
            cars.push_back(vector<int>{position[i], speed[i]});
        
        sort(cars.begin(), cars.end());
        
        vector<float> time;
        for(auto c : cars)
            time.push_back((target - c[0] * 1.0) / (c[1] * 1.0));
        
        
        stack<float> s;
        
        
        for(int i = 0; i<time.size(); i++){
            while(!s.empty() && s.top() <= time[i])
                s.pop();
            s.push(time[i]);
        }
        
        return s.size();
        
        
    }
};