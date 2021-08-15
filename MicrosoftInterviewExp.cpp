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
// 10. Regular Expression Matching - https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
/*******************************************************************************/
// 44. Wildcard Matching - https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string str, string pattern) {
        int m=pattern.size();
        int n=str.size();
        
        bool dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                dp[i][j]=false;
            }
        }
        dp[0][0]=true;            //if both string and pattern are empty
        
        for(int i=1;i<=m;i++){
           if(pattern[i-1]=='*')  //if pattern starts with '*' 
            dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
                else if(pattern[j-1]=='*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};
/*******************************************************************************/
// 25. Reverse Nodes in k-Group - https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseK(ListNode* head, int k, int count){
        if(count < k)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = NULL;
        int c = 0;
        while(curr != NULL && c < k){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            c++;
        }
        if(nex != NULL){
            ListNode* restHead = reverseK(nex, k, count - k);
            head->next = restHead;
        }
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* test = head;
        
        while(test){
            count++;
            test = test->next;
        }
        return reverseK(head, k, count);
    }
};
/*************************************************************************************************/