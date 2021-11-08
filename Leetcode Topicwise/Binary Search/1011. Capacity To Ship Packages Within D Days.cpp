https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxm = 0;
        int minm = 0;
        for(auto x : weights){
            maxm += x;
            minm = max(minm, x);
        }
        int l = minm;
        int h = maxm;
        
        while(l < h){
            int mid = l + (h - l) / 2;
            
            int d = 1;
            int cap = 0;
            for(int i = 0; i<weights.size();){
                int x = weights[i];
                if(cap + x <= mid){
                    cap +=x;
                    i++;                    
                }
                else{
                    d++;
                    cap = 0;
                }
            }
            if(d > days)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};
