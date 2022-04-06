class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int top  = 0;
        int bot = matrix.size() - 1;
        
        while(top <= bot){
            int row = top + (bot - top) / 2;
            
            if(target > matrix[row][matrix[0].size() - 1])
                top = row + 1;
            
            else if(target < matrix[row][0])
                bot = row - 1;
            
            else
                break;
        }
        
        if(top > bot) // if first binary search couldn't find any row which could potentially have the target element then we return false
            return false;
        
        int row = top + (bot - top) / 2;
        
        int l = 0;
        int r = matrix[0].size() - 1;
        
        while(l <= r){
            int col = l + (r - l) / 2;
            
            if(target > matrix[row][col])
                l = col + 1;
            
            else if(target < matrix[row][col])
                r = col - 1;
            
            else 
                return true;
        }
        
        return false;
    }
};