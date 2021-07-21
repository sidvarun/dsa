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