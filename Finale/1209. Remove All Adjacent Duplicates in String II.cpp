https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/392933/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution

class Solution {
public:
    string removeDuplicates(string s, int k) {
     
        stack<pair<char, int>> st;
        
        for(auto c : s){
            
            if(st.empty() || st.top().first != c)
                st.push({c, 1});
            
            else
                st.top().second++;
            
            if(st.top().second == k)
                st.pop();
        }
        
        string res = "";
        
        while(!st.empty()){
            while(st.top().second--)
                res += st.top().first;
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};