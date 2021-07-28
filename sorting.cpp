// Merge Without Extra Space - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
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
/**********************************************************************************************/
// Quick Sort - https://practice.geeksforgeeks.org/problems/quick-sort/1#
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low < high){
            int p = partition(arr, low, high);
            quickSort(arr, low, p-1);
            quickSort(arr, p, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int p = arr[high];
       int i = low - 1;
       for(int j = low; j<high; j++){
           if(arr[j] <= p){
               i++;
               swap(arr[i], arr[j]);
           }
       }
       swap(arr[i+1], arr[high]);
       return i+1;
    }
};
/*********************************************************************************************************/
// Kth smallest element  - https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int arr[], int low, int high){
       // Your code here
       int pi = low + (rand()%(high-low+1));
       int p = arr[pi];
       swap(arr[pi], arr[high]);
       int i = low - 1;
       for(int j = low; j<high; j++){
           if(arr[j] <= p){
               i++;
               swap(arr[i], arr[j]);
           }
       }
       swap(arr[i+1], arr[high]);
       return i+1;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        while(l<=r){
            int p = partition(arr, l, r);
            if(p == k-1)
                return arr[p];
            else if(p > k-1)
                r = p - 1;
            else if(p < k-1)
                l = p + 1;
        }
        return -1;
    }
};
/*********************************************************************************************/
// Chocolate Distribution Problem  - https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        int res = INT_MAX;
        for(int i = 0; i + m - 1 < n; i++){
            int diff = a[i + m - 1] - a[i];
            res = min(res, diff);
        }
        return res;
    }   
};
/*********************************************************************************************************/
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