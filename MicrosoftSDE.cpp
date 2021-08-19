// 1. Group Anagram  - https://practice.geeksforgeeks.org/problems/group-anagram/1/?track=mts-hashing&batchId=341
// Editorial -  https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Code here
        vector<vector<string>> res;
        vector<string> temp = strs;
        map<string, vector<string>> m;
        for(int i = 0; i<temp.size(); i++){
            sort(temp[i].begin(), temp[i].end());
            m[temp[i]].push_back(strs[i]);
        }
        for(auto v = m.begin(); v != m.end(); v++){
            vector<string> subres = v->second;
            sort(subres.begin(), subres.end());
            res.push_back(subres);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
/*********************************************************************************/
// 166. Fraction to Recurring Decimal - https://leetcode.com/problems/fraction-to-recurring-decimal/
/*
    For the decimal part to recur, the remainder should recur. So we maintain the remainders we have seen. 
    Once we see an existing remainder, we have reached the end of the recurring part (enclose it with a )). 
    Moreover, insert the ( to the starting index of the recurring part by maintaining a mapping from each remainder
    to the index of the corresponding digit and using it to retrieve the starting index.



    For those without fractional parts or with non-recursive fractional points, we may find them out by % or zero remainder. 
    Some other problems that need to be considered include the sign and overflow (-2147483648 / -1).
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) {
            return "0";
        }
        string ans;
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }
        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r) {
            return ans;
        }
        ans += '.';
        unordered_map<long, int> rs;
        while (r) {
            if (rs.find(r) != rs.end()) {
                ans.insert(rs[r], "(");
                ans += ')';
                break;
            }
            rs[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};
/******************************************************************************************************/
// 3. Largest subarray with 0 sum  - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/?track=mts-hashing&batchId=341#
// Editorial :
int maxLen(int A[], int n)
{
    // Map to store the previous sums
    map<int, int> p;
    int sum = 0; // Initialize the sum of elements
    int len = 0; // Initialize result

    for (int i = 0; i < n; i++)
    {
        // Add current element to sum
        sum += A[i];
        if(A[i] == 0 and len == 0)
            len = 1;
        if(sum == 0)
            len = i + 1;

        // Look for this sum in Hash table
        if (p.find(sum) != p.end())
        {
            // If this sum is seen before, then update max_len
            len = max(len, i - p[sum]);
        }
        else
        {
            // Else insert this sum with index in hash table
            p[sum] = i;
        }
    }
    return len;
}
////////////////////////////////////////////////////////////////
int maxLen(int A[], int n)
{
    // Your code here
    map<int, int> m;
    int res = 0;
    m[A[0]] = 0;
    int pSum = A[0];
    for(int i = 1; i<n; i++){
        pSum += A[i];
        if(pSum == 0)
            res = i + 1;
        else if(m.find(pSum) != m.end())
            res = max(res, i - m[pSum]);
        else
            m[pSum] = i;
    }
    return res;
}
/****************************************************************************************************/
// 4. Longest consecutive subsequence  - https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1/?track=mts-hashing&batchId=341
class Solution{
  public:
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //using a Set to store elements.
        unordered_set<int> S;
        int ans = 0;
 
        //inserting all the array elements in Set.
        for (int i = 0; i < n; i++)
           S.insert(arr[i]);
 
        //checking each possible sequence from the start.
        for (int i = 0; i < n; i++)
        {
           //if current element is starting element of a sequence then only 
           //we try to find out the length of sequence.
           if (S.find(arr[i] - 1) == S.end())
           {
               
                int j = arr[i];
                //then we keep checking whether the next consecutive elements
                //are present in Set and we keep incrementing the counter.
                while (S.find(j) != S.end())
                j++;
 
            //storing the maximum count.
            ans = max(ans, j - arr[i]);
            }
        }
        //returning the length of longest subsequence
        return ans;
    }
};
/*****************************************************************************************************/
// 16. 3Sum Closest - https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int left = 1;
        int right = n - 1;
        for(int i = 0; i<nums.size() - 2 ; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            left = i + 1;
            right = n - 1;
            while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(target == sum)
                return sum;
            if(abs(target - sum) < abs((long long)target - res)){
                res = sum;
            }
            if(target > sum)
                left++;
            else
                right--;
            
            }
        }
        return res;
    }
};
/***************************************************************/
// 6. Find missing in second array  - https://practice.geeksforgeeks.org/problems/in-first-but-second5423/1/?track=mts-hashing&batchId=341
public:
	vector<long long> findMissing(long long a[], long long b[],  
                 int n, int m) 
	{ 
	    // Store all elements of  
	    // second array in a hash table 
	    unordered_set <long long> s;
	    vector<long long> ans;
	    for (int i = 0; i < m; i++) 
	        s.insert(b[i]); 
	  
	    // Print all elements of  
	    // first array that are not 
	    // present in hash table 
	    for (int i = 0; i < n; i++) 
	        if (s.find(a[i]) == s.end()) 
	            ans.push_back(a[i]);
	    return ans;
	} 
/**************************************************************************/