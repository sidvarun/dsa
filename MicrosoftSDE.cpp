// 1. Group Anagram  - https://practice.geeksforgeeks.org/problems/group-anagram/1/?track=mts-hashing&batchId=341
// Editorial -  https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Code here
        vector<vector<string>> res;
        vector<string> temp = strs;
        map<string, vector<string>> m;
        for(int i = 0; i<temp.size(); i++){
            sort(temp[i].begin(), temp[i].end());
            m[temp[i]].push_back(strs[i]);
        }
        for(auto v = m.begin(); v != m.end(); v++){
            vector<string> subres = v->second;
            sort(subres.begin(), subres.end());
            res.push_back(subres);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
/*********************************************************************************/
// 166. Fraction to Recurring Decimal - https://leetcode.com/problems/fraction-to-recurring-decimal/
/*
    For the decimal part to recur, the remainder should recur. So we maintain the remainders we have seen. 
    Once we see an existing remainder, we have reached the end of the recurring part (enclose it with a )). 
    Moreover, insert the ( to the starting index of the recurring part by maintaining a mapping from each remainder
    to the index of the corresponding digit and using it to retrieve the starting index.



    For those without fractional parts or with non-recursive fractional points, we may find them out by % or zero remainder. 
    Some other problems that need to be considered include the sign and overflow (-2147483648 / -1).
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) {
            return "0";
        }
        string ans;
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }
        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r) {
            return ans;
        }
        ans += '.';
        unordered_map<long, int> rs;
        while (r) {
            if (rs.find(r) != rs.end()) {
                ans.insert(rs[r], "(");
                ans += ')';
                break;
            }
            rs[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};
/******************************************************************************************************/

