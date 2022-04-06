class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1000000009;
        
        while(l < r){
            int hrs = 0;
            int mid = l + (r - l) / 2;
            for(auto &x : piles)
                hrs += (int) ceil((x  * 1.0) / mid); // finding number of hours needed to eat all bananas in the current pile
    
            if(hrs <= h)
                r = mid;
            else
                l = mid + 1;
        }
        
        return l;
    }
};