https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int partition(vector<int>&nums, int l, int h){
        int i = l - 1;
        int p = rand()%(h - l + 1) + l;
        swap(nums[p], nums[h]);
        for(int j = l; j < h; j++){
            if(nums[j] < nums[h]){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[h]);
        return i + 1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        
        k = n - k + 1;
        
        while(l <= r){
            int p = partition(nums, l, r);
            
            if(p == k - 1)
                return nums[p];
            
            else if(p > k - 1)
                r = p - 1;
            else
                l = p + 1;
        }
        return -1;
    }
};
