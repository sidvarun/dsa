class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        
        while(l < r){
            int mid = l + (r - l) / 2;
            
            if(mid < sqrt(num))
                l = mid + 1;
            else
                r = mid;
        }
        return l == sqrt(num);
    }
};