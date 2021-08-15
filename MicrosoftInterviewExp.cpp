// 1326. Minimum Number of Taps to Open to Water a Garden - 
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min = 0;
        int max = 0;
        int res = 0;
        // int n = ranges.size();
        while(max<n){
            for(int i = 0; i<n+1; i++){
                if(i - ranges[i] <= min && i + ranges[i] > max){
                    max = i + ranges[i];
                }
            }
            if(min == max)
                return -1;
            res++;
            min = max;
        }
        return res;
    }
};
/*********************************************************/
// 1024. Video Stitching - https://leetcode.com/problems/video-stitching/
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int max = 0;
        int min = 0;
        int res = 0;
        while(max < time){
            for(int i = 0; i<clips.size(); i++){
                if(clips[i][0] <= min && clips[i][1] > max)
                    max = clips[i][1];
            }
            if(min == max)
                return -1;
            res++;
            min = max;
        }
        return res;
    }
};
/***********************************************************************/
// 74. Search a 2D Matrix - https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = m * n - 1;
        while(l<=h){
            int mid = (l + h) / 2;
            if(matrix[mid/n][mid%n] == target)
                return true;
            if(matrix[mid/n][mid%n] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};
/*****************************************************************************/