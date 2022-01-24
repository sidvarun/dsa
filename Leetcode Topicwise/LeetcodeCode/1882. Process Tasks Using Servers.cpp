class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = tasks.size();
        vector<int> res(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> available, unavailable;

        for(int i = 0; i<servers.size(); i++)
            available.push(vector<int>{servers[i], i});
        
        int time = 0;
        
        for(int i = 0; i<tasks.size(); i++){
            time = max(i, time);
            
            if(available.size() == 0)
                time = unavailable.top()[0];
            while(!unavailable.empty() && unavailable.top()[0] == time){
                available.push(vector<int>{unavailable.top()[1], unavailable.top()[2]});
                unavailable.pop();
            }

            auto curr = available.top();
            available.pop();
            unavailable.push(vector<int>{time + tasks[i], curr[0], curr[1]});
            res[i] = curr[1];
        }
        return res;
    }
};