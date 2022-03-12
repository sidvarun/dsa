class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &x : nums)
            s.insert(x);
        
        int res = 0;
        
        for(auto &n : s){
            if(s.find(n - 1) == s.end()){
                int subRes = 1;
                int num = n + 1;
                while(true){
                    if(s.find(num) != s.end()){
                        subRes++;
                        num++;
                    }         
                    else
                        break;
                }
                res = max(res, subRes);
            }
        }
        return res;
    }
};