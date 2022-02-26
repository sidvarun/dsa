class Solution {
public:
    static bool cmp(int a, int b){
        string n1 = to_string(a);
        string n2 = to_string(b);
        if(n1 + n2 > n2 + n1)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        bool leadingZero = true;
        for(int x : nums){
            if(leadingZero && x == 0)
                continue;
            leadingZero = false; 
            res += to_string(x);
        }
        return res == "" ? "0" : res;
    }
};