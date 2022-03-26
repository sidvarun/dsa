class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(int i = 97; i <= 122; i++){
            m1[(char) i] = 0;
            m2[(char) i] = 0;
        }
        for(auto x : s1)
            m1[x]++;
        int res = 0;
        for(int i = 0; i<s1.length(); i++)
            m2[s2[i]]++;
        
        for(int i = 97; i <= 122; i++){
            if(m1[(char) i] == m2[(char) i])
                res++;
        }
        
        int l = 0;
        int r = s1.length();
        
        for(; r<s2.length(); r++){
            if(res == 26)
                return true;
            if(m2[s2[l]] == m1[s2[l]])
                res--;
            m2[s2[l]]--;
            if(m2[s2[l]] == m1[s2[l]])
                res++;
            l++;
            if(m1[s2[r]] == m2[s2[r]])
                res--;
            m2[s2[r]]++;
            if(m2[s2[r]] == m1[s2[r]])
                res++;
        }
        return res == 26;
        
        
    }
};