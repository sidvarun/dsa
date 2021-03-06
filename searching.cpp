// Binary Search - https://practice.geeksforgeeks.org/problems/binary-search/1
class Solution{
public:
    int binarysearch(int arr[], int n, int k){
        // code here
        int l = 0; 
        int h = n-1;
        int mid;
        while(l<=h){
            mid = (l + h)/2;
            if(arr[mid] == k)
                return mid;
            else if(arr[mid] > k)
                h = mid - 1;
            else 
                l = mid + 1;
        }
        return -1;
    }
};
/*******************************************************************************/
// First and last occurrences of x - https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#

vector<int> find(int arr[], int n , int x )
{
    // code here
    
        vector<int> res;
        int l = 0; 
        int h = n-1;
        int mid;
        bool val = false;
        while(l<=h){
            mid = (l + h)/2;
            if(arr[mid] == x){
                val = true;
                break;
            }
            else if(arr[mid] > x)
                h = mid - 1;
            else 
                l = mid + 1;
        }
        if(val == false){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int pos1 = mid;
        int pos2 = mid;

        while(arr[pos1] == x && pos1<n)
            pos1++;
        
        while(arr[pos2] == x && pos2>=0)
            pos2--;
        
        res.push_back(pos2+1);
        res.push_back(pos1-1);
        return res;
}
/**********************************************************************************************************/
// Search an element in sorted and rotated array - https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array0959/1/?track=amazon-searching&batchId=192#

int bSearch(vector<int> arr, int low, int high, int x)
{
	if(low > high)
		return -1;

	int mid = (low + high) / 2;

	if(arr[mid] == x)
		return mid;

	else if(arr[mid] > x)
		return bSearch(arr, low, mid - 1, x);

	else
		return bSearch(arr, mid + 1, high, x);
}
int Search(vector<int> v, int k) {
    //code here
    int i = 1;
    int n = v.size();
    while(i<n && v[i] > v[i-1]){
        i++;
    }
    int pivot = i - 1;
    if(v[pivot] == k)
        return pivot;
    else if(v[pivot]>k && v[n-1]<k)
        return bSearch(v, 0, pivot-1, k);
    else if(v[pivot]>k && v[n-1]>k)
        return bSearch(v, pivot+1, n-1, k);
    return -1;
}
/***************************************************************************************/
// Count Squares - https://practice.geeksforgeeks.org/problems/count-squares3649/1#
class Solution {
  public:
    int countSquares(int n) {
        // code here
        int low = 1;
        int high = n;
        long long mid;
        int res = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(mid*mid > n)
                high = mid - 1;
            else if(mid * mid < n){
                res = mid;
                low = mid+1;
            }
            else{
                res = mid - 1;
                break;
            }
        }
        return res;
    }
};
/*****************************************************************************************/
// Find Missing And Repeating - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *res = new int(2);
        
        int i;
        for(i = 0; i<n; i++){
            if(arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = arr[abs(arr[i]) - 1] * -1;
            else
                res[0] = abs(arr[i]);
        }
        for(i = 0; i<n; i++){
            if(arr[i]>0){
                res[1] = i+1;
                break;
            }
        }
        return res;
    }
};
/********************************************************************************************/
// Majority Element - https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
int majorityElement(int a[], int size)
    {
        
        // your code here
        
        int res = 0;
        int count = 1;
        
        for(int i = 1; i<size; i++){
            if(a[res] != a[i])
                count--;
            else
                count++;
            if(count == 0){
                res = i;
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i<size; i++){
            if(a[i] == a[res])
                count++;
        }
        if(count>size/2)
            return a[res];
        return -1;
    }
/***************************************************************************************************/
// Find Pair Given Difference - https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#
int binarysearch(int arr[], int n, int k){
        // code here
        int l = 0; 
        int h = n-1;
        int mid;
        while(l<=h){
            mid = (l + h)/2;
            if(arr[mid] == k)
                return mid;
            else if(arr[mid] > k)
                h = mid - 1;
            else 
                l = mid + 1;
        }
        return -1;
    }
bool findPair(int arr[], int n, int x){
    //code
   sort(arr, arr+n);
   int key;
   for(int i = 0; i<n; i++){
       key = x + arr[i];
       int val = binarysearch(arr, n, key);
       if(val != -1 && val != i) 
         return true;
   }
   return false;
    
}
/*******************************************************************************************************/

// Find All Four Sum Numbers - https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        // int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        for(int i = 0; i < arr.size() - 3; i++){
            for(int j = i+1; j < arr.size() - 2; j++){
                int l = j+1;
                int r = arr.size() - 1;
                while(l<r){
                  int sum = arr[i] + arr[j] + arr[l] + arr[r];
                  if(sum == k){
                      vector<int> t;
                      t.push_back(arr[i]);
                      t.push_back(arr[j]);
                      t.push_back(arr[l]);
                      t.push_back(arr[r]);
                      res.push_back(t);
                      l++;
                      r--;
                  }
                  else if(sum > k)
                    r--;
                  else
                    l++;
                }
                
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
/**************************************************************************************/
// Count triplets with sum smaller than X - https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#

class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long x)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    long long count = 0;
	    for(int i = 0; i<n-2; i++){
	        int j = i+1;
	        int k = n-1;
            while(j<k){
                long long sum =  arr[i] + arr[j] + arr[k];
                if(sum >= x)
                    k--;
                else{
                    count += k-j;
                    j++;
                }
            }
	        
	    }
	    return count;
	}
};
/************************************************************************************************************/
// Zero Sum Subarrays - https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<int, int> m;
        m[arr[0]] = 1;
        ll count = 0;
        ll psum = arr[0];
        if(arr[0] == 0)
            count = 1;
        for(int i = 1; i<n; i++){
            psum += arr[i];
            if(psum == 0 )
                count++;
            if(m.find(psum) != m.end())
                count += m[psum];
            m[psum]++;
        }
        return count;
    }
};
/****************************************************************************/
// Allocate minimum number of pages  - https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

class Solution 
{
    public:
    bool isValid(int a[], int n, int minPg, int k){
        int sum = 0;
        int s = 1;
        for(int i = 0; i<n; i++){
            sum += a[i];
            if(sum > minPg){
                s++;
                sum = a[i];
            }
        }
        if(s > k)
            return false;
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int k) 
    {
        //code here
        int res = INT_MAX;
        int low = INT_MIN;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += a[i];
            low = max(low, a[i]);
        }
        int subres = low;
        int high = sum;
        while(low <= high){
            int minPg = (low + high) / 2;
            if(isValid(a, n, minPg, k)){
                res = min(res, minPg);
                high = minPg - 1;
            }
            else{
                low = minPg + 1;
            }
        }
        return res;
    }
};
/**************************************************************************************************/