https://leetcode.com/problems/koko-eating-bananas/

// Explanation
// Binary search between [1, 10^9] or [1, max(piles)] to find the result.
// Time complexity: O(NlogM)

// (p + m - 1) / m equal to ceil(p / m) (just personal behavior)

// Here you find another similar problem.
// 774. Minimize Max Distance to Gas Station

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int maxm = 0;
        for(auto x : piles)
            maxm = max(maxm, x);
        int l = 1;
        int h = maxm;
        while(l < h){
            int mid = l + (h - l) / 2;
            int total = 0;
            for(auto x : piles)
                total += ceil((double) x / mid);
            if(total > hrs)
                l = mid + 1;
            else 
                h = mid;
        }
        return l;
    }
};