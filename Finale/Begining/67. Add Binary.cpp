class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res;
        
        int n = max(a.length(), b.length());
        
        int carry = 0;
        
        for(int i = 0; i < n; i++){
            int digit1 = 0;
            int digit2 = 0;
            
            if(i < a.length())
                digit1 = a[i] - '0';
            
            if(i < b.length())
                digit2 = b[i] - '0';
            
            int total = digit1 + digit2 + carry;
            
            int num = total % 2;
            string s = to_string(num);
            
            res = s + res;
            
            carry = total / 2;
        }
        
        if(carry != 0)
            res = "1" + res;
        
        return res;
    }
};