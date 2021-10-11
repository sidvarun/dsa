https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for(int i = 0; i<n;){
            nums[index++] = nums[i];
            while(i < n && nums[i] == nums[index - 1])
                i++;
        }
        return index;
    }
};
