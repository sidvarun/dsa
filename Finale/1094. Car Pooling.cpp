class Solution {
public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        sort(trips.begin(), trips.end(), cmp);
        
        int n = trips.size();
        
        int pass = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {dest, src, pass}
        
        for(int i = 0; i < n; i++){
            while(!pq.empty() && trips[i][1] >= pq.top()[0]){
                auto curr = pq.top();
                pass -= curr[2];
                pq.pop();
            }
        
            pass += trips[i][0];
            if(pass > capacity)
                return false;                
            pq.push(vector<int>{trips[i][2], trips[i][1], trips[i][0]});            
        }
        
        return true;
    }
};