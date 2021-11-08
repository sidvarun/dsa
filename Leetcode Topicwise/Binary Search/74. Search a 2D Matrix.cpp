https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0;
        int h = m * n - 1;
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            int i = mid / n;
            int j = mid % n;
            
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};