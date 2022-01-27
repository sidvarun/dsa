class Solution {
public:
    int time;
    char prevTask;
    int prevTaskFreq;
    int leastInterval(vector<char>& tasks, int n) {
        // {instances, task} -> available
        // {nextFreeTime, task, instances} -> unavailable
        priority_queue<vector<int>, vector<vector<int>>> available;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> unavailable;
        
        unordered_map<char, int> m;
        
        for(auto c : tasks){
            if(m.find(c) == m.end())
                m[c] = 1;
            else
                m[c]++;
        }
        
        for(auto i = m.begin(); i != m.end(); i++){
            int p = i->first - 'A';
            available.push(vector<int>{i->second, p});
        }
        
        time = 0;
        while(!available.empty() || !unavailable.empty()){
            while(!unavailable.empty() && unavailable.top()[0] <= time){
                auto curr = unavailable.top();
                unavailable.pop();
                available.push(vector<int>{curr[2], curr[1]});
            }
            if(available.empty() == true){
                time++;
                continue;
            }
            auto curr = available.top();
            available.pop();
            
            prevTask = curr[1];
            prevTaskFreq = curr[0] - 1;

            if(prevTaskFreq > 0){
                int t = time + n + 1;
                unavailable.push(vector<int>{t, prevTask, prevTaskFreq});
            }
            time++;
        }
        return time;
    }
};