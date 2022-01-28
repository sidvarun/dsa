class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> m;
        m['T'] = 0;
        m['F'] = 0;
        
        int res = INT_MIN;
        int maxFreq = INT_MIN;
        int l = 0;
        for(int r = 0; r < answerKey.length(); r++){
            
            m[answerKey[r]]++;
            maxFreq = max(maxFreq, m[answerKey[r]]);
            
            while(r - l + 1 - maxFreq > k){
                m[answerKey[l]]--;
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        return res;
    }
};