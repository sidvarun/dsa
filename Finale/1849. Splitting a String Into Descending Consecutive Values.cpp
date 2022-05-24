class Solution {
public:
    int n;
    string s;
    bool dfs(int i, unsigned long long int preVal){
        if(i == n)
            return true;
        
        for(int j = i; j < n; j++){
            string str = s.substr(i, j - i + 1);
            unsigned long long int val = 0;
            for(auto c : str)
                val = val * 10 + (c - '0');
            if(preVal == val + 1 && dfs(j + 1, val))
                return true;
        }
        return false;
    }
    
    bool splitString(string ss) {
        s = ss;
        n = s.length();
        
        for(int i = 0; i < n-1; i++){
            string str = s.substr(0, i + 1);
            unsigned long long int val = 0;
            for(auto c : str)
                val = (val * 10) + (c - '0');
            if(dfs(i + 1, val))
                return true;
        }
        return false;
    }
};