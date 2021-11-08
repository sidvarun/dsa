https://leetcode.com/contest/weekly-contest-266/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxm = 0;
        for(auto x : quantities)
            maxm = max(maxm, x);
        int l = 1;
        int h = maxm;
        while(l < h){
            int mid = l + (h - l) / 2;
            int totalStores = 0;
            for(auto x : quantities)
                totalStores += ceil((double) x / mid);
            if(totalStores > n)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};
