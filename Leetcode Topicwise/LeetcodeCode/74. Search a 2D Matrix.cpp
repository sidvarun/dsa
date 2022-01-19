class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // finding the row
        int u = 0;
        int d = m - 1;
        int row = -1;
        while(u <= d){
            int mid = (d - u) / 2 + u;
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1]){
                row = mid;
                break;
            }
            if(target > matrix[mid][n - 1])
                u = mid + 1;
            else if(target < matrix[mid][0])
                d = mid - 1;
        }
        if(row == -1)
            return false;
        // find target in row
        
        int l = 0;
        int r = n - 1;
        while(l<=r){
            int mid = (r - l) / 2 + l;
            if(matrix[row][mid] == target)
                return true;
            if(matrix[row][mid] > target)
                r = mid - 1;
            else if(matrix[row][mid] < target)
                l = mid + 1;
        }
        return false;
    }
};