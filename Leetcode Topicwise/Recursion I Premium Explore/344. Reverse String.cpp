class Solution {
public:
    void recursiveReverse(vector<char>& s, int i, int j){
        if(i > j)
            return;
        swap(s[i], s[j]);
        recursiveReverse(s, i + 1, j - 1);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        recursiveReverse(s, 0, n - 1);
    }
};