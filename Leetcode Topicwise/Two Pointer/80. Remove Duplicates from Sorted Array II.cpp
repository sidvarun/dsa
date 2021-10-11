https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        int left = 2;
        for(int right = 2; right<n; right++){
            if(nums[right] != nums[left - 2]){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};