https://leetcode.com/problems/move-zeroes/

Soln : https://leetcode.com/problems/move-zeroes/discuss/172432/THE-EASIEST-but-UNUSUAL-snowball-JAVA-solution-BEATS-100-(O(n))-%2B-clear-explanation

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int snowSize = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0)
                snowSize++;
            else
                swap(nums[i], nums[i - snowSize]);
        }
    }
};
/********************************************************/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        while(left < n && nums[left] != 0)
                    left++;
        for(int right = left + 1; right < n; right++){
            if(nums[right] != 0 && right > left){
                swap(nums[left], nums[right]);
                while(left < n && nums[left] != 0)
                    left++;
                if(left == n)
                    return;
            }
        }
    }
};
