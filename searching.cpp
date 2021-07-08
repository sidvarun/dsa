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