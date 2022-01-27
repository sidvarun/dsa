class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        unordered_map<char, int> ref;
        string s = "balloon";
        
        for(auto c : s){
            if(ref.find(c) == ref.end())
                ref[c] = 1;
            else
                ref[c]++;
        }

        
        for(auto c : text){
            if(m.find(c) == m.end())
                m[c] = 1;
            else
                m[c]++;
        }
        
        int res = INT_MAX;
        
        for(int i = 0; i<s.length(); i++)
            res = min(res, m[s[i]]/ref[s[i]]);
        
        return res;
    }
};