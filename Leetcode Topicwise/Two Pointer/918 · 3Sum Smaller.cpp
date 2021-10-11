https://www.lintcode.com/problem/918/description

// Here duplicate elements are also allowed it seems
// Code for removing duplicates has been commented out

class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            // if(i > 0 && nums[i] == nums[i - 1])
            //     continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                long long sum = (long long)nums[i] + (long long)nums[left] + (long long)nums[right];
                if(sum >= target)
                    right--;
                else{
                    // left++;
                    // while(left < right && nums[left] == nums[left - 1])
                    //     left++;
                    res += right - left; // is sum<target for this value of nums[left] the it will be smaller for all right from right to left because the array is sorted. 
                    left++;
                }
            }
        }
        return res;
    }
};