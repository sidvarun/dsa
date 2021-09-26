// 925. Long Pressed Name -  https://leetcode.com/problems/long-pressed-name/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length();
        int m = typed.length();
        int i = 0;
        int j = 0;
        if(name[i] != typed[j])
                return false;
        while(i<n){
            if(name[i] == typed[j]){
                i++;
                j++;
            }
            else if(name[i-1] == typed[j])
                j++;
            else
                return false;
        }
        while(j<m){
            if(typed[j] != name[n-1])
                return false;
            j++;
        }
        if(i == n)
            return true;
        return false;
    }
};
/*******************************************************************/
// Product array puzzle  - https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

/*
    Compute product of all elements of array in from left and right in left(let) and right(let) array.
    Then start traversing from i = 0. For every element the answer will left(i-1) * right(i+1).
    Handle corner cases for first and last element.
*/
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        vector<long long int> res(n, 1);
        vector<long long int> left;
        vector<long long int> right;
        left.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            left.push_back(left[i-1] * nums[i]);
        }

        right.push_back(nums[n-1]);
        for(int i = n-2; i>=0; i--)
            right.push_back(right[n-i-2] * nums[i]);
        reverse(right.begin(), right.end());
        for(int i = 0; i<n; i++){
        }
        for(int i = 0; i<n; i++){
            if(i>0)
                res[i] *= left[i-1];
            if(i<n-1)
                res[i] *= right[i+1];
        }
        return res;
    }
};
/*****************************************************************************************/
