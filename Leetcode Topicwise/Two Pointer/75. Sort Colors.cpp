class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = 0, k = nums.size();
        while(j < k){
            if(nums[j] == 0){
                i++;
                swap(nums[j], nums[i]);
                j++;
            }
            else if(nums[j] == 1)
                j++;
            else{
                k--;
                swap(nums[j], nums[k]);
            }
        }
    }
};