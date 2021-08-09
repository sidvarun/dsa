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
/*
Problem Link - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Solution 1  - Sort the array ,  Time- O(NLogN) Space - O(1)
Soultion 2 - Hashing , Time - (O(2*N)), Space - O(N)
Solution 3 - Using XOR , Time - O(5*N), Space - O(1)
Problem in my words - There are 'n' numbers in the array
                    - Out of those n numbers , one number is repeted 2 times and one number is missing.
                    - Find the dupicate number and missing number
                    
 How it got striked in mind that XOR should be used?  
 ANS - due to XOR property which is :  x ^ x = 0                     -----  let this be (1) 
                                    :  x ^ x ^ x = x                 -----  let this be (2) 
                                    :  x = x (not XORED with anyone) -----  let this be (3) 
                                    :  If the XOR result ( of lets say (x and y) ) has ith bit set , it means either x has ith bit set or y has ith bit set.  ----  let this be (4) 
                                   
 Observation 1. Out of these n numbers , n-2 numbers appear exactly once.
             2. If the given array is XORED with the range of [1 to n] , These n-2 numbers discussed above will be ommitted (refer (1) ).
                2.1 Lets take an example to understand what i said above -
                2.2 Let the array be [4 3 6 2 1 1] , range is [1 to 6]
                2.3 Out of 6 numbers , 4 numbers which are - 2,3,4,6 will be ommitted if this array is XORED with the range[1 to 6] (refer (1) ).
                2.4 Illustration - (1^2^3^4^5^6) ^ (4^3^6^2^1^1)
                                 2.4.1 Remaining value after XOR: (1^5) ^ (1^1)
                
             3. After those n-2 numbers are ommitted , then remaining 2 numbers (repeted) will result into one of those 2 numbers (refer (2)).
                3.1 Lets continue the previous example to understand what i said above
                3.2 (1^5) ^ (1^1)
                3.3 (5) ^ (1^1^1)
                3.4 (5) ^ (1)
                3.5 In the above example repeted number was 1 which was appeared two times.When these two 1's got XORED with the 1 of the range[1 to 6],
                     result was 1.In other words,(1^1^1)=1
                    
             4. So Conclusion from point 3 is that the duplicate number is still remaining in the result.
             
             5.Moving back to the remaining XOR value of the example , there is a number 5 in the result.
               5.1 This number 5 is not being XORED with anyone so it is still 5. (Refer (3)
               5.2 Why is it not XORED with anyone? because 5 was missing in the given array [4 3 6 2 1 1].
               5.3 This 5 belongs to the range[1 to 6].Since 5 was missing in the given array,it remained as it is in the result.
               
             6. So Conclusion from point 5 is that the missing number is also present in the result along with the duplicate number.
             
             7. These two are the numbers which we needed finally.But In coding , these numbers will be XORED and they will be in the form of a single number.
                7.1 The above statement means to say that the result - 5 ^ 1 will be computed and saved as the 4 (5^1=4).
             
             8.We need to find out the missing number and the duplicate number from 4.Thats our task.
             
             9.To acomplish the task in point 8, lets think about (4th point of XOR property).
               9.1 So we have to find a bit(ith) that is set in 4.
               9.2 We have to find a number which has ith bit set and another number which has ith bit not-set.
               9.3 To do this, we should look at all such possibilities which satisfies 9.2
               9.4 To look at all possibilities , Divide the range[1 to n] in two buckets.
               9.5 One bucket has numbers(from range [1-n] ) which has ith bit set and another bucket has numbers(from range [1-n]) which has ith bit not-set.
               9.6 Now we have the numbers,rather than trying all possibilities,we should ommit those n-2 numbers which were discussed in point 1.
               9.7 These n-2 numbers are not part of either duplicate number and repeted number so they must be Omitted by XORRING them with the numbers in the buckets.
               9.8 After you ommit those n-2 numbers you are left with two numbers , one in each bucket which your ANSWER!!
               
               9.9 Let me take an example of the above steps from 9.1 to 9.8
                   9.9.1 Result after XORRING in point 7 was 4.
                   9.9.2 2nd bit in 4 is set.If x^y=4,then x is a number which has 2nd bit set and y is a number which has 2nd bit not set.
                   9.9.3 Its obvious that missing number and duplicate number are from the range [1 to 6]
                   9.9.4 Looking at all possibilites by diving the range [1 2 3 4 5 6] into two buckets.Refer 9.5
                   9.9.5 Bucket-1 contains [4 5 6] AND bucket-2 contains [1 2 3]
                   9.9.6 Rather than trying out all possibilities by taking a pair,(each number from both buckets), we should first ommit
                         those n-2=4 numbers.Those 4 numbers were 2 3 4 6.
                   9.9.7 Dividing these 4 numbers and XORRING them to ommit.
                   9.9.8 Bucket-1 contains [4 4 5 6 6] AND bucket-2 contains [1 2 2 3 3]
                   9.9.9 After Xorring all numbers of Bucket-1, it contains a number 5.
                   9.9.10 After Xorring all numbers of Bucket-2, it contains a number 1.
                   9.9.11 You Got your 2 numbers which are the answers to your question.
                   
            10.To figure which of these numbers is the missing number and which of these is the duplicate number , you can check it by traversing the given array.
*/
class Solution
{
public:
    int *findTwoElement(int *arr, int n) 
    {
        int complete_xor=0,arr_xor=0,tot_xor=0;
        for(int i=1;i<=n;i++)
        {
            complete_xor^=i;
            arr_xor^=arr[i-1];
        }
        tot_xor = complete_xor ^ arr_xor;
        
        //seperate the missing number and repeting number from total_xor
        
        int till=(log(n)/log(2))+1,bit;
        
        for(int i=0;i<=till;i++)
        {
            if( ((1<<i) & tot_xor)!=0){bit=i;break;}
        }
        
        int buck1=0,buck2=0;

        for(int i=1;i<=n;i++)
        {
          if( ((1<<bit) & i) !=0 ) buck1^=i;
          else buck2^=i;
          if( ((1<<bit) & arr[i-1]) !=0 )buck1^=arr[i-1];
          else buck2^=arr[i-1];
        }
        int ok=0;
        for(int i=0;i<n;i++)
        {
            if(buck1==arr[i]){ok=1;break;}
        }
        int *ans=new int[2];
        if(ok==1)
        {
          ans[0]=buck1;
          ans[1]=buck2;
        }
        else  
        {
          ans[0]=buck2;
          ans[1]=buck1; 
        }
        return ans;
    }
};
/*************************************************************************/