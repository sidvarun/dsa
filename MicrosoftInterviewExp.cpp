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
// Similar problem
/*
    Divide the LinkedList into k segments and print the segments in reverse order. 
    First I gave him the brute force approach and then he told me to optimize the 
    space complexity of the code and finally code the solution. He also asked me 
    to dry run on few test cases. eg:1-2-3-4 k=2 output:3-4-1-2.

    Hint -> First reverse the linked list in groups of size K and then reverse the entire linked list.
*/
/*************************************************************************************************/
// 836. Rectangle Overlap - https://leetcode.com/problems/rectangle-overlap/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        int X1 = rec2[0];
        int Y1 = rec2[1];
        int X2 = rec2[2];
        int Y2 = rec2[3];
        
        if(x2<=X1 || x1>=X2 || y2<=Y1 || y1>=Y2)
            return false;
        return true;
        

    }
};

// Editorial 
/*
    Intuition

    If the rectangles do not overlap, then rec1 must either be higher, lower, to the left, or to the right of rec2.

    Algorithm

    The answer for whether they don't overlap is LEFT OR RIGHT OR UP OR DOWN, where OR is the logical OR, and LEFT is a boolean that represents whether rec1 is to the left of rec2. The answer for whether they do overlap is the negation of this.

    The condition "rec1 is to the left of rec2" is rec1[2] <= rec2[0], that is the right-most x-coordinate of rec1 is left of the left-most x-coordinate of rec2. The other cases are similar.

    Note: we should also check if either of the rectangle is actually a line. If this is the case, then we cannot have any positive overlapping according to the definition.
*/
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        // check if either rectangle is actually a line
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            // the line cannot have positive overlap
            return false;
        }

        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
}
/************************************************************************************/
// Overlapping rectangles  - https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1
class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        int x1 = L1[0];
        int y1 = R1[1];
        int x2 = R1[0];
        int y2 = L1[1];
        int X1 = L2[0];
        int Y1 = R2[1];
        int X2 = R2[0];
        int Y2 = L2[1];
        
        if(x2<=X1 || x1>=X2 || y2<=Y1 || y1>=Y2)
            return false;
        return true;
        
    }
};
/*************************************************************************************/