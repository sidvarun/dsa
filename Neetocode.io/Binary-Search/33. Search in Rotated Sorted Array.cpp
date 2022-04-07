class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] >= nums[0]){ // check if mid is in left sorted half
                if(target > nums[mid])
                    l = mid + 1;
                else{
                    if(target >= nums[0])
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
            }
            
            else{
                if(target < nums[mid])
                    r = mid - 1;
                else{
                    if(target <= nums[nums.size() - 1])
                        l = mid + 1;
                    else
                        r = mid - 1;
                }                
            }
        }
        return -1;
    }
};