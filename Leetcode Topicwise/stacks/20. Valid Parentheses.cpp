class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = { {')', '('}, {'}', '{'}, {']' , '['} };
        stack<char> st;
        for(int i = 0; i<s.length(); i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else if(st.empty() == false && m[c] == st.top())
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};

Time Complexity => O(n)
Space Complexity => O(n), In the worst case, all the opening brackets will be pushed to the stack, so n/2 opening brackets pushed to the stack.