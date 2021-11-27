class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> res;
        for(int i = n - 1; i>=0; i--){
            int curr = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            res.push_back(curr);
        }
        if(carry == 1)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};