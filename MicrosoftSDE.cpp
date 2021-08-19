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
// 7. Top K Frequent Elements in Array - |  - https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1/?track=mts-hashing&batchId=341
/*
    Using hash table to store the frequency of occurrence of each number in the given array. 
    Now we traverse this hash table and create an array freq_arr[] which stores these (number, frequency) tuples.
    Sort this freq_arr[] on the basis of the conditions defined in the problem statement. 
    Print the first k numbers of this freq_arr[].

*/
class Solution {
  public:
    // Back-end complete function Template for C++

    static bool compare(pair<int, int> p1, pair<int, int> p2) {
        // If 2 elements have same frequency then return larger element
        if (p1.second == p2.second) return (p1.first > p2.first);

        // Else return element with larger frequency
        else
            return (p1.second > p2.second);
    }

    vector<int> topK(vector<int>& nums, int k) {
        vector<int>
            result; // vector to store elements that have top k frequencies
        unordered_map<int, int> ump; // frequency map

        // add all elements to frequency map
        for (int i = 0; i < nums.size(); i++) ump[nums[i]]++;

        // convert frequency map to vector
        vector<pair<int, int> > frequency(ump.begin(), ump.end());

        // sort frequency vector using user defined compare function
        sort(frequency.begin(), frequency.end(), compare);

        // add first k elements from sorted vector to result
        for (int i = 0; i < k; i++) result.push_back(frequency[i].first);

        return result;
    }
};
/*****************************************************************************************/
// 8. Intersection of two arrays  - https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1/?track=mts-hashing&batchId=341
 int NumberofElementsInIntersection (int a[], int b[] , int n, int m)
    {
        //using set to store the elements.
    	unordered_set<int> s1;
        int count = 0;
        
        //we insert all the elements of first array in set s1. 
    	for(int i=0;i<n;i++)
    		s1.insert(a[i]);
        
        //iterating over the second array.
    	for(int i=0;i<m;i++)
    	{
    	    //if current element already exists in set, we update the counter.
    		if(s1.find(b[i]) != s1.end()){
    		    
    		    //erasing element from set because if same element is present 
    		    //again in the array we don't need to count it again. 
    		    s1.erase(b[i]);
    		    
    		    //incrementing the counter. 
    		    count++;
    		}
    	}
    	//returning the counter.
    	return count;
    }
};
/********************************************************************************************/
// 9. Array Pair Sum Divisibility Problem - https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1/?track=mts-hashing&batchId=341#
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        // An odd length array cannot be divided into pairs
        if (n & 1) return false;

        // Create a frequency array to count occurrences
        // of all remainders when divided by k.
        map<int, int> freq;

        // Count occurrences of all remainders
        for (int i = 0; i < n; i++) freq[nums[i] % k]++;

        // Traverse input array and use freq[] to decide
        // if given array can be divided in pairs
        for (int i = 0; i < n; i++) {
            // Remainder of current element
            int rem = nums[i] % k;

            // If remainder with current element divides
            // k into two halves.
            if (2 * rem == k) {
                // Then there must be even occurrences of
                // such remainder
                if (freq[rem] % 2 != 0) return false;
            }

            // If remainder is 0, then there must be two
            // elements with 0 remainder
            else if (rem == 0) {
                if (freq[rem] & 1) return false;
            }

            // Else number of occurrences of remainder
            // must be equal to number of occurrences of
            // k - remainder
            else if (freq[rem] != freq[k - rem])
                return false;
        }
        return true;
    }
};
//////////////////////////////////////////////////////////
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        map<int, int> m;
        for(int i = 0; i<nums.size(); i++)
            m[nums[i] % k]++;
        if(m[0] % 2 != 0)
            return false;
        for(int i = 1; i<k; i++){
            if(m[i] != m[k - i])
                return false;
        }
        return true;
    }
};
/****************************************************************************************************/
// 560. Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k/
// See editorial method 4 for explanation
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(m.find(sum-k) != m.end())
                res += m[sum - k];
            m[sum]++;
        }
        return res;
    }
};
///////////
class Solution{
    public:
    // Function to find number of subArrays
    // with k exactly equal to k.
    int findSubArraySum(int Arr[], int N, int k)
    {
        // STL map to store number of subArrays
        // starting from index zero having
        // particular value of k.
        unordered_map<int, int> prevk;
     
        int res = 0;
     
        // k of elements so far.
        int currk = 0;
     
        for (int i = 0; i < N; i++) {
     
            // Add current element to k so far.
            currk += Arr[i];
     
            // If currk is equal to desired k,
            // then a new subArray is found. So
            // increase count of subArrays.
            if (currk == k)
                res++;
     
            // currk exceeds given k by currk
            //  - k. Find number of subArrays having
            // this k and exclude those subArrays
            // from currk by increasing count by
            // same amount.
            if (prevk.find(currk - k) != prevk.end())
                res += (prevk[currk - k]);
     
            // Add currk value to count of
            // different values of k.
            prevk[currk]++;
        }
        return res;
    } 
};
/***************************************************************************/
// 974. Subarray Sums Divisible by K - https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Explanation - https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/413234/DETAILED-WHITEBOARD!-BEATS-100-(Do-you-really-want-to-understand-It)

class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        map<int, int> m;
        int n = arr.size();
        int res = 0;
        int sum = 0;
        int rem = 0;
        m[0] = 1;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            res += m[rem];
            m[rem]++;
        }
        return res;
    }
};
/**********************************************************************************/


