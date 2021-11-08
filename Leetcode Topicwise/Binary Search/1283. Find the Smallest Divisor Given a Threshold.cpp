https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxm = 0;
        for(auto x : nums)
            maxm = max(maxm, x);
        int l = 1;
        int h = maxm;
        while(l < h){
            int mid = l + (h - l) / 2;
            int sum = 0;
            for(auto x : nums)
                sum += ceil((double) x / mid);
            if(sum > threshold)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};