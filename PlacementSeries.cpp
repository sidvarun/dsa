// Two Sum - https://leetcode.com/problems/two-sum/submissions/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            if(m.find(target - nums[i]) != m.end()){
                res.push_back(m[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
/***************************************************************/
// 493. Reverse Pairs - https://leetcode.com/problems/reverse-pairs/
// Discussion Solution
class Solution {
private:
    int count;
   
    void checkCount(vector<int>& nums, int start, int mid, int end){

        // two pointers;
        int l = start, r = mid + 1;
        while(l <= mid && r <= end){
            if((long)nums[l] > (long) 2 * nums[r]){
                count += (mid - l + 1);
                r++;
            }else{
                l++;
            }
        }
       // worst case might be nlog(n) 
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
        
        
        
        //every step sort
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start == end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums,start, mid);
        mergeSort(nums,mid+1,end);
        
        checkCount(nums,start,mid,end);
        return;
        
    }
public:
    int reversePairs(vector<int>& nums) {
        if(!nums.size())return 0;
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};
//Striver SOlution 
// giving overflow
class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int res = 0; 
        int j = mid + 1;
        for(int i = low; i<=mid; i++){
            if(j<=high && (((long)arr[i]/2 + (long)arr[i]%2LL) > (long)arr[j])
                j++;
            res += j - (mid + 1);
        }
        int left[n1];
        int right[n2];
        for(int i = 0; i<n1; i++){
            left[i] = arr[low + i];
        }
        for(int i = 0; i<n2; i++){
            right[i] = arr[mid + 1 + i];
        }
        int i = 0;
        int k = low;
        // for(int i = 0; i<n1; i++){
        //     while(j<n2 && left[i] > 2*right[j])
        //         j++;
        //     res += j;
        // }
        j=0;
        while(i<n1 && j<n2){
            if(left[i] <= right[j]){
                arr[k++] = left[i];
                i++;
            }
            else{
                arr[k++] = right[j];
                j++;
            }
        }
        while(i<n1){
            arr[k++] = left[i++];
        }
        while(j<n2){
            arr[k++] = right[j++];
        }
        return res;
    }

    int mergeSort(vector<int> &arr, int low, int high){
        int res = 0;
        if(low < high){
            int mid = low + (high - low)/2;
            res = mergeSort(arr, low, mid);
            res += mergeSort(arr, mid + 1, high);
            res += merge(arr, low, mid, high);
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
/**********************************************************************************************/
// Number of Unique Paths - https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        //code here
        int dp[m][n];
        for(int i = m-1; i>=0; i--)
            for(int j = n-1; j>=0; j--)
                if(i == m-1 || j == n-1)
                    dp[i][j] = 1;
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
        
        
    }
};
/*************************************************************************************************/
// 287. Find the Duplicate Number - https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int f = 0; 
        int s = 0;
        do{
            s = a[s];
            f = a[a[f]];
        }while(s != f);
        f = 0;
        while(s != f){
            s = a[s];
            f = a[f];
        }
        return s;
    }
};
/*****************************************************************************************/
// 268. Missing Number - https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0;
        int xor2 = 0;
        int n = nums.size();
        for(int i = 0; i<=n; i++)
            xor1 = xor1 ^ i;
        
        for(int i = 0; i<n; i++)
            xor2 = xor2 ^ nums[i];
        int res = xor1 ^ xor2;
        return res;
    }
};
/*************************************************************************/
