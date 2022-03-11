// Binary Search

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1;
        int r = n;
        int res = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            long long numRows = ((long long)mid * (mid + 1)) / 2;
            
            if(numRows <= n){
                res = max(res, mid);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return res;
    }
};

/**********************************************/


class Solution {
public:
    int arrangeCoins(int n) {
        
        int res = 0;
        
        int rowNum = 1;
        
        while(n - rowNum >= 0){
            res++;
            n -= rowNum++;
        }
        
        return res;
    }
};


/***************/

