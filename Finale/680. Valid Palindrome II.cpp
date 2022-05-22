class Solution {
public:
    bool validPalindrome(string s) {
        
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j){
            
            if(s[i] == s[j]){
                i++;
                j--;
                continue;
            }
            
            string s1 = s.substr(i, j - i);
            string s2 = s.substr(i + 1, j - i);
            
            string revs1 = s1;
            reverse(revs1.begin(), revs1.end());
            
            string revs2 = s2;
            reverse(revs2.begin(), revs2.end());
            
            cout<< revs1<<" "<<revs2;
            
            return ((s1 == revs1) || (s2 == revs2));
        }
        
        return true;
    }
};