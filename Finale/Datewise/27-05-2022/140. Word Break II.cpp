class Solution {
public:
    unordered_set<string> st;
    vector<string> res;
    
    void dp(int i, string s, string subres){
        
        if(i == s.length()){
            subres.pop_back();
            res.push_back(subres);
            return;
        }

        for(int j = i; j<s.length(); j++){
            string str = s.substr(i, j - i + 1);
            if(st.find(str) != st.end()){
                dp(j + 1, s, subres + str + " ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict)
            st.insert(word);
                
        string str = "";
        
        dp(0, s, str);
        
        return res;
    }
};