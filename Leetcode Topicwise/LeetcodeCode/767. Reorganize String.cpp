class Solution {
public:
    string reorganizeString(string s) {
        
        priority_queue<vector<int>> pq;
        unordered_map<char, int> m;
        
        for(auto c : s){
            if(m.find(c) == m.end())
                m[c] = 1;
            else
                m[c]++;
        }
        for(auto i = m.begin(); i != m.end(); i++)
            pq.push(vector<int>{i->second, i->first});
        
        char lastChar;
        int lastCharFreq;
        string res = "";
        for(int i = 0; i<s.length(); i++){
            auto curr = pq.top();
            pq.pop();
            lastChar = curr[1];
            lastCharFreq = curr[0] - 1;
            res += curr[1];
            if(lastCharFreq > 0)
                pq.push(vector<int>{lastCharFreq, lastChar});
            if(pq.empty() == true)
                return "";
        }
        return res;
    }
};