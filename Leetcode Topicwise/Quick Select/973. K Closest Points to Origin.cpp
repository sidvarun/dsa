https://leetcode.com/problems/k-closest-points-to-origin/

https://leetcode.com/problems/k-closest-points-to-origin/discuss/220235/Java-Three-solutions-to-this-classical-K-th-problem.

class Solution {
public :
    int partition(vector<int>&nums, vector<vector<int>>& points, int l, int h){
        int i = l - 1;
        int p = rand()%(h - l + 1) + l;
        swap(nums[p], nums[h]);
        points[p].swap(points[h]);
        for(int j = l; j < h; j++){
            if(nums[j] < nums[h]){
                i++;
                swap(nums[i], nums[j]);
                points[i].swap(points[j]);
            }
        }
        swap(nums[i + 1], nums[h]);
        points[i + 1].swap(points[h]);
        return i + 1;
    }
    int findKthLargest(vector<int>& nums, vector<vector<int>>& points, int k) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        
        // k = n - k + 1;
        
        while(l <= r){
            int p = partition(nums, points, l, r);
            
            if(p == k - 1)
                return p;
            
            else if(p > k - 1)
                r = p - 1;
            else
                l = p + 1;
        }
        return -1;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<int> nums;
        for(int i = 0; i<points.size(); i++){
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            nums.push_back(d);
        }
        int kPos = findKthLargest(nums, points, k);
        vector<vector<int>> res;
        if(kPos != -1){
            for(int i = 0; i<=kPos; i++)
                res.push_back(points[i]);            
        }

        return res;
    }
};
