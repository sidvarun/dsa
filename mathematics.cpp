// Trailing zeroes in factorial  - https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1
class Solution
{
public:
    int trailingZeroes(int n){
        // Write Your Code here
        int res = 0;
        for(int i = 5; i<=n; i *= 5){
            res += n/i;
        }
        return res;
    }
};
/***************************************************************************/
