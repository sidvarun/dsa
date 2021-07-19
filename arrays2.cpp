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