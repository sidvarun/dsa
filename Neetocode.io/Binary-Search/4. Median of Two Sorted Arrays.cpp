class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() < nums2.size()){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        
        if(nums2.size() == 0){
            if(nums1.size() % 2 == 0)
                return ((nums1[nums1.size() / 2] + nums1[nums1.size() / 2 + 1])) / 2.0;
            else
                return nums1[nums1.size() / 2];
        }
        
        int total = nums1.size() + nums2.size();
        
        int half = total / 2;
        
        
        int l = -1;
        
        int r = nums2.size();
        
        while(true){
            
            int i = l + (r - l) / 2;
            
            int j = half - i - 2;
            
            int nums2Left = i >= 0 ? nums2[i] : INT_MIN;
            int nums2Right = i + 1 <= nums2.size() - 1 ? nums2[i + 1] : INT_MAX;
            
            int nums1Left = j >= 0 ? nums1[j] : INT_MIN;
            int nums1Right = j + 1 <= nums1.size() - 1 ? nums1[j + 1] : INT_MAX;
            
            if(nums1Left <= nums2Right && nums2Left <= nums1Right){
                if(total % 2 == 0){
                    return ((max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) * 1.0) / 2;
                }
                else{
                    return (nums1Right, nums2Right) * 1.0;
                }
            }
            else if(nums2Left > nums1Right)
                r = i - 1;
            else
                l = i + 1;
        }
        return -1.0;
    }
};