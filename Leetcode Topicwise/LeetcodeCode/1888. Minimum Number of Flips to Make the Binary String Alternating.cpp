// More efficient code
class Solution {
public:
    int minFlips(string s) {
        string str = s + s;
        
        int n = s.length();
        
        string t1 = "";
        string t2 = "";
        
        for(int i = 0; i < 2*n; i++){
            if(i % 2 == 0){
                t1 += '0';
                t2 += '1';
            }
            else{
                t1 += '1';
                t2 += '0';
            }
        }
        
        int res1 = 0;
        int res2 = 0;
        int ans = n;
      
        int l = 0;
        int r = 0;
        
        for(r = 0; r < 2*n; r++){
            res1 += (str[r] - '0') ^ (t1[r] - '0');
            res2 += (str[r] - '0') ^ (t2[r] - '0');
            if(r - l + 1 > n){
                res1 -= (str[l] - '0') ^ (t1[l] - '0');
                res2 -= (str[l] - '0') ^ (t2[l] - '0');
                l++;
            }
            if(r - l + 1 == n)
                ans = min(ans, min(res1, res2));
        }
        return ans;
    }
};



/****************************************************************************************************/


class Solution {
public:
    int minFlips(string s) {
        string str = s + s;
        
        int n = s.length();
        
        string t1 = "";
        string t2 = "";
        
        for(int i = 0; i < 2*n; i++){
            if(i % 2 == 0){
                t1 += '0';
                t2 += '1';
            }
            else{
                t1 += '1';
                t2 += '0';
            }
        }
        
        int res1 = 0;
        int res2 = 0;
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            if(str[i] != t1[i])
                res1++;
            if(str[i] != t2[i])
                res2++;
        }
        ans = min(res1, res2);
        int l = 0;
        int r = n;
        
        while(r < 2 * n){
            res1 -= (str[l] - '0') ^ (t1[l] - '0');
            res2 -= (str[l] - '0') ^ (t2[l] - '0');
            l++;
            res1 += (str[r] - '0') ^ (t1[r] - '0');
            res2 += (str[r] - '0') ^ (t2[r] - '0');
            r++;
            ans = min(ans, min(res1, res2));
        }
        return ans;
    }
};