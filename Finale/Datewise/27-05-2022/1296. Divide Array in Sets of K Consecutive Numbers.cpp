class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto h : nums){
            if(m.find(h) == m.end()){
                m[h] = 1;
                pq.push(h);
            }
            else
                m[h]++;
        }
        

        while(!pq.empty()){
            int curr = pq.top();
            if(m[curr] == 0){
                pq.pop();
                continue;
            }
            for(int i = curr; i < curr + k; i++){
                if(m.find(i) == m.end() || m[i] == 0)
                    return false;
                
                m[i]--;
            }
        }
        
        return true;

    }
};