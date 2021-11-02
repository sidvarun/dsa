https://leetcode.com/problems/valid-triangle-number/

https://leetcode.com/problems/valid-triangle-number/discuss/128135/A-similar-O(n2)-solution-to-3-Sum

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int k = 2; k<n; k++){
            int i = 0;
            int j = k - 1;
            while(i < j){
                if(nums[i] + nums[j] <= nums[k])
                    i++;
                else{
                    res += j - i;
                    j--;
                }
            }
        }
        return res;
    }
};
