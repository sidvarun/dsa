class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        vector<string> ans;
        if(s.length() < 10)
            return ans;
        unordered_map<string, int> m;
        
        string str = s.substr(0, 10);
        m[str] = 1;
        int j = 10;
        
        while(j < s.length()){
            str.erase(0, 1);
            str.push_back(s[j++]);
            if(m.find(str) == m.end()){
                m[str] = 1;
            }
            else
                res.insert(str);
        }
        
        for(auto x : res)
            ans.push_back(x);
        return ans;
    }
};