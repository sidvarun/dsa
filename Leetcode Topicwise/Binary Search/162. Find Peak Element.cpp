https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int peakRec(vector<int> &nums, int l, int h){
        if(l == h)
            return l;
        int mid = l + (h - l) / 2;
        if(nums[mid] > nums[mid + 1])
            return peakRec(nums, l, mid);
        return peakRec(nums, mid + 1, h);
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return peakRec(nums, 0, n - 1);
    }
};