https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxm = 0;
        int minm = 0;
        for(auto x : nums){
            maxm += x;
            minm = max(minm, x);
        }
        int l = minm;
        int h = maxm;
        
        while(l < h){
            int mid = l + (h - l) / 2;
            
            int noOfSubArrays = 1;
            int cap = 0;
            for(int i = 0; i<nums.size();){
                int x = nums[i];
                if(cap + x <= mid){
                    cap +=x;
                    i++;                    
                }
                else{
                    noOfSubArrays++;
                    cap = 0;
                }
            }
            if(noOfSubArrays > m)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};