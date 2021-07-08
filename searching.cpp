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