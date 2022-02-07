class Solution {
public:
    string decodeString(string s){
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ']')
                st.push(s[i]);
            
            else{
                string substr = "";
                while(st.top() != '['){
                    substr.insert(0, 1, st.top());
                    st.pop();
                }
                st.pop();
                string digit = "";
                while(!st.empty() && st.top() - '0' >= 0 && st.top() - '0' <= 9){
                    digit.insert(0, 1, st.top());
                    st.pop();
                }
                
                int n = stoi(digit);
                
                string str = "";
                while(n--)
                    str += substr;
                
                for(int i = 0; i<str.length(); i++)
                    st.push(str[i]);
            }
        }
        string res;
        while(!st.empty()){
            res.insert(0, 1, st.top());
            st.pop();
        }
        return res;
    }
};