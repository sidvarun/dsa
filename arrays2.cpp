// Find minimum and maximum element in an array - https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> res;
    res.second = a[0];
    res.first = a[0];
    for(int i = 1; i<n; i++){
        if(a[i]>res.second)
            res.second = a[i];
        if(a[i]<res.first)
            res.first = a[i];
    }
    return res;
}
/*****************************************************************/
// Sort an array of 0s, 1s and 2s - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            if(a[mid] == 0){
                swap(a[mid], a[low]);
                mid++;
                low++;
            }
            else if(a[mid] == 2){
                swap(a[mid], a[high]);
                high--;
            }
            else
                mid++;
        }
    }
    
};
/********************************************************************/
// Union of two arrays - https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        int res = 0;
        int i = 0;
        int j = 0;
        map<int, int> mp;
        while(i<n && j<m){
            mp[a[i]] = 1;
            mp[b[j]] = 1;
            i++;
            j++;
        }
        while(i<n){
            mp[a[i]] = 1;
            i++;
        }
        while(j<m){
            mp[b[j]] = 1;
            j++;
        }
        return mp.size();
    }
};
/*********************************************************************************/
// Intersection of two arrays - https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
class Solution{
    public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        // Your code goes here
        map<int, int> mp;
        map<int, int> res;
        if(n<m){
            for(int i = 0; i<n; i++){
                mp[a[i]] = 1;
            }
            for(int i = 0; i<m; i++){
                if(mp.find(b[i]) != mp.end())
                    res[b[i]] = 1;
            }
        }
        else{
            for(int i = 0; i<m; i++){
                mp[b[i]] = 1;
            }
            for(int i = 0; i<n; i++){
                if(mp.find(a[i]) != mp.end())
                    res[a[i]] = 1;
            }
        }
        return res.size();
    }
};
/*********************************************************************************************/
// Cyclically rotate an array by one  - https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
void rotate(int arr[], int n)
{
    int last = arr[n-1];
    for(int i = n-1; i>0; i--)
        arr[i] = arr[i-1];
    arr[0] = last;
    
}
/*****************************************************************************************/
// Maximum of all subarrays of size k - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        
        for(int i = 0; i < min(k, n); i++)
        {
            while(!dq.empty() and arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        vector<int> res;
        
        for(int i = k; i < n; i++)
        {
            res.push_back(arr[dq.front()]);
            
            while(!dq.empty() and (i - k) >= dq.front())
            {
                dq.pop_front();
            }
            
            while(!dq.empty() and arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        res.push_back(arr[dq.front()]);
        
        return res;
    }
};
/*************************************************************/

// Minimize the Heights II - https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int, int>> v;
        vector<int> taken(n);

        // we will store all possible heights in a vector
        for (int i = 0; i < n; i++) {
            if (arr[i] - k >= 0) {
                v.push_back({arr[i] - k, i});
            }
            v.push_back({arr[i] + k, i});
        }
        sort(v.begin(), v.end());
        int elements_in_range = 0;
        int left = 0;
        int right = 0;

        // By two pointer we will traverse v and whenever we will get a range
        // in which all towers are included, we will update the answer.
        while (elements_in_range < n && right < v.size()) {
            if (taken[v[right].second] == 0) {
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }
        int ans = v[right - 1].first - v[left].first;
        while (right < v.size()) {
            if (taken[v[left].second] == 1) {
                elements_in_range--;
            }
            taken[v[left].second]--;
            left++;

            while (elements_in_range < n && right < v.size()) {
                if (taken[v[right].second] == 0) {
                    elements_in_range++;
                }
                taken[v[right].second]++;
                right++;
            }

            if (elements_in_range == n) {
                ans = min(ans, v[right - 1].first - v[left].first);
            } else {
                break;
            }
        }
        return ans;
    }
};
/******************************************************************************/
// Merge Without Extra Space  - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m){
	    // code here
	    int i = n-1;
	    int j = 0;
	    while( i>=0 && j<m){
	        if(arr1[i] > arr2[j]){
	            swap(arr1[i], arr2[j]);
	            i--;
	            j++;
	        }
	        else 
	            break;
	    }
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);
	}
};
/******************************************************************************/
// Next Permutation  - https://practice.geeksforgeeks.org/problems/next-permutation5226/1

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int i = n-1;
        int ind1 = -1;
        while(i>0){
            if(arr[i-1]<arr[i]){
                ind1 = i-1;
                break;
            }
            i--;
        }
        if(ind1 == -1)
        {
            reverse(arr.begin(), arr.end());
            
            return arr;
        }
        for(i=n-1; i>ind1; i--){
            if(arr[i]>arr[ind1])
                break;
        }
        int ind2 = i;
        swap(arr[ind1], arr[ind2]);
        reverse(arr.begin()+ind1+1, arr.end());    
        return arr;
    }
};
/******************************************************************************************/
// Count Inversions - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long low, long long mid, long long high){
        long long n1 = mid - low + 1;
        long long n2 = high - mid;
        long long left[n1];
        long long right[n2];
        for(int i = 0; i<n1; i++){
            left[i] = arr[low + i];
        }
        for(int i = 0; i<n2; i++){
            right[i] = arr[mid + 1 + i];
        }
        long long i = 0;
        long long j = 0;
        long long res = 0;
        long long k = low;
        while(i<n1 && j<n2){
            if(left[i] <= right[j]){
                arr[k++] = left[i];
                i++;
            }
            else{
                arr[k++] = right[j];
                if(left[i] > 2*right[j])
                    res += n1 - i;
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

    long long mergeSort(long long arr[], long long low, long long high){
        long long res = 0;
        if(low < high){
            long long mid = low + (high - low)/2;
            res += mergeSort(arr, low, mid);
            res += mergeSort(arr, mid + 1, high);
            res += merge(arr, low, mid, high);
        }
        return res;
    }
    long long inversionCount(long long arr[], long long N){
        return mergeSort(arr, 0, N - 1);
    }
};
/************************************************************************************/
// Count pairs with given sum  - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++)
            m[arr[i]]++;
        for(int i = 0; i<n; i++){
            if(arr[i] * 2 == k && m.find(k - arr[i]) != m.end())
                res += m[k - arr[i]] - 1;
            else if(m.find(k - arr[i]) != m.end())
                res += m[k - arr[i]];
        }
        return res/2;
    }
};
/*************************************************************************************/
// Common elements - https://practice.geeksforgeeks.org/problems/common-elements1132/1#

class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> res;
            set<int> s;
            int p1 = 0;
            int p2 = 0;
            int p3 = 0;
            while(p1<n1 && p2<n2 && p3<n3){
                int minm = min(a[p1], min(b[p2], c[p3]));
                if(a[p1] == b[p2] && b[p2] == c[p3]){
                    s.insert(a[p1]);
                    p1++;
                    p2++;
                    p3++;
                }
                else if(minm == a[p1])
                    p1++;
                else if(minm == b[p2])
                    p2++;
                else if(minm == c[p3])
                    p3++;
            }
            for(auto i : s)
                res.push_back(i);
            return res;
        }

};
/**************************************************************************************/
// Subarray with 0 sum  - https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        map<int, int> m;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            if(sum == 0)
                return true;
            if(m.find(sum) != m.end())
                return true;
            m[sum] = 1;
        }
        return false;
    }
};
/**************************************************************************************/
// Factorials of large numbers  - https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

class Solution {
public:
    void factRec(int n, vector<int> &res){
        if(n == 0 || n == 1){
            res.push_back(1);
            return;
        }
        factRec(n-1, res);
        int carry = 0;
        int calc = 0;
        for(int i = res.size() - 1; i >= 0; i--){
            calc = (res[i] * n + carry) % 10;
            carry = (res[i] * n + carry) / 10;
            res[i] = calc;
        }
        while(carry != 0){
            res.insert(res.begin(), carry%10);
            carry /= 10;
        }
    }
    vector<int> factorial(int n){
        // code here
        vector<int> res;
        factRec(n, res);
        return res;
    }
};
/***********************************************************************************************/
// Maximum Product Subarray - https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

class Solution{
public:

	// Function to find maximum product subarray
    long long maxProduct(int *arr, int n) {
	    // Variables to store maximum and minimum
	    // product till ith index.
	    long long minVal = arr[0];
	    long long maxVal = arr[0];

	    long long maxProduct = arr[0];

	    for (int i = 1; i < n; i++) {

	        // When multiplied by -ve number,
	        // maxVal becomes minVal
	        // and minVal becomes maxVal.
	        if (arr[i] < 0) swap(maxVal, minVal);

	        // maxVal and minVal stores the
	        // product of subarray ending at arr[i].
	        maxVal = max((long long)arr[i], maxVal * arr[i]);
	        minVal = min((long long)arr[i], minVal * arr[i]);

	        // Max Product of array.
	        maxProduct = max(maxProduct, maxVal);
	    }

	    // Return maximum product found in array.
	    return maxProduct;
	}
};
/******************************************************************************************************/
// Longest consecutive subsequence  - https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      set<int> s;
      for(int i = 0; i<n; i++)
        s.insert(arr[i]);
      int c = 1;
      int res = INT_MIN;
      for (auto itr = s.begin(); itr != prev(s.end(), 1); itr++){
            if( *itr + 1 == *next(itr,1)){
                c++;
                    // cout<<*itr + 1<< " "<<*next(itr,1)<<endl; 
            }
            else{
                res = max(res, c);
                c = 1;
            }
       }
       res = max(c, res);
       return res;
    }
};
/*************************************************************************************************************/
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist){
        int res = 0;
        if(rugs[0]%dist == 0)
            res = rugs[0]/dist - 1;
        else
            res = rugs[0]/dist;
        for(int i = 1; i<rugs.size() - 1; i++){
            int diff = rugs[i+1] - rugs[i];
            if(diff > dist){
                if(diff % dist == 0)
                    res += diff/dist - 1;
                else
                    res += diff/dist;
            }
        }
        return res;
    }
};
/***************************************************************************************************************/
// Largest subarray with 0 sum - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

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
            res = max(res, i + 1);
        if(m.find(pSum) != m.end())
            res = max(res, i - m[pSum]);
        else
            m[pSum] = i;
    }
    return res;
}
/***************************************************************************************/
// Largest subarray of 0's and 1's  - https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1#

class Solution{
  public:
        // Your code here
    int maxLen(int A[], int n){
        // Your code here
        for(int i = 0; i<n; i++)
            if(A[i] == 0)
                A[i] = -1;
        map<int, int> m;
        int res = 0;
        m[A[0]] = 0;
        int pSum = A[0];
        for(int i = 1; i<n; i++){
            pSum += A[i];
            if(pSum == 0)
                res = max(res, i + 1);
            if(m.find(pSum) != m.end())
                res = max(res, i - m[pSum]);
            else
                m[pSum] = i;
        }
        return res;
    }
};
/************************************************************************/