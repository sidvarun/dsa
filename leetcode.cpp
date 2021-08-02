// https://leetcode.com/problems/largest-number-after-mutating-substring/submissions/
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.length();
        bool val = false;
        int i = 0;
        while(i<n){
            int curr = num[i] - '0';
            if(curr < change[curr] || (val && curr == change[curr])){
                val = true;
                char c = '0' + change[curr];
                num[i] = c;
                i++;
            }
            else if(val)
                break;
            else
                i++;
        }          
        return num;
    }
};
/*********************************************************/