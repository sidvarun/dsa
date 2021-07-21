// Push all 0's to the end of the array
void pushZerosToEnd(int arr[], int n)
{
    int count = 0; // Count of non-zero elements

    // Traverse the array. If element encountered is non-
    // zero, then replace the element at index 'count'
    // with this element
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i]; // here count is
                                   // incremented

    // Now all non-zero elements have been shifted to
    // front and  'count' is set as index of first 0.
    // Make all elements 0 from count to end.
    while (count < n)
        arr[count++] = 0;
}
/**************************************************/
// left rotate an array by d

// Naive
#include <iostream>
#include <cmath>
using namespace std;

void lRotateOne(int arr[], int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
}

void leftRotate(int arr[], int d, int n)
{
    for (int i = 0; i < d; i++)
    {
        lRotateOne(arr, n);
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5}, n = 5, d = 2;

    cout << "Before Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    leftRotate(arr, d, n);

    cout << "After Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// Method 2
#include <iostream>
#include <cmath>
using namespace std;

void leftRotate(int arr[], int d, int n)
{
    int temp[d];

    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = 0; i < d; i++)
    {
        arr[n - d + i] = temp[i];
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5}, n = 5, d = 2;

    cout << "Before Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    leftRotate(arr, d, n);

    cout << "After Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// Method 3

#include <iostream>
#include <cmath>
using namespace std;

void reverse(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[high], arr[low]);

        low++;
        high--;
    }
}

void leftRotate(int arr[], int d, int n)
{
    reverse(arr, 0, d - 1);

    reverse(arr, d, n - 1);

    reverse(arr, 0, n - 1);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5}, n = 5, d = 2;

    cout << "Before Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    leftRotate(arr, d, n);

    cout << "After Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/*********************************************************/
// Leaders in an array

#include <iostream>
#include <cmath>
using namespace std;

void leaders(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{

    int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;

    leaders(arr, n);
}

// efficient method

#include <iostream>
#include <cmath>
using namespace std;

void leaders(int arr[], int n)
{
    int curr_ldr = arr[n - 1];

    cout << curr_ldr << " ";

    for (int i = n - 2; i >= 0; i--)
    {
        if (curr_ldr < arr[i])
        {
            curr_ldr = arr[i];

            cout << curr_ldr << " ";
        }
    }
}

int main()
{

    int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;

    leaders(arr, n);
}
/*************************************************************************/

// Maximum difference Problem with order

#include <iostream>
#include <cmath>
using namespace std;

int maxDiff(int arr[], int n)
{
    int res = arr[1] - arr[0], minVal = arr[0];

    for (int i = 1; i < n; i++)
    {

        res = max(res, arr[i] - minVal);

        minVal = min(minVal, arr[i]);
    }

    return res;
}

int main()
{

    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;

    cout << maxDiff(arr, n);
}
/************************************************************************************/
// Frequency of each element in a sorted array

#include <iostream>
#include <cmath>
using namespace std;

void printFreq(int arr[], int n)
{
    int freq = 1, i = 1;

    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }

        cout << arr[i - 1] << " " << freq << endl;

        i++;
        freq = 1;
    }
}

int main()
{

    int arr[] = {10, 10, 20, 30, 30, 30}, n = 6;

    printFreq(arr, n);
}
/**********************************************************************************/

// stock buy and sell problem link -> https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
class Solution
{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        // code here
        vector<vector<int>> v;
        vector<int> temp;
        int i = 0;
        while (i < n - 1)
        {
            int buy = 0;
            int sell = 0;
            while (i < n - 1 && A[i + 1] <= A[i])
                i++;
            if (i == n - 1)
                return v;
            buy = i;
            i++;
            while (i < n - 1 && A[i + 1] >= A[i])
                i++;

            temp.push_back(buy);
            temp.push_back(i);
            v.push_back(temp);
            temp.clear();
        }
        return v;
    }
};
/**********************************************************************************************/

// Trapping Rainwater problem

#include <iostream>
#include <cmath>
using namespace std;

int getWater(int arr[], int n)
{
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int lMax = arr[i];

        for (int j = 0; j < i; j++)
            lMax = max(lMax, arr[j]);

        int rMax = arr[i];

        for (int j = i + 1; j < n; j++)
            rMax = max(rMax, arr[j]);

        res = res + (min(lMax, rMax) - arr[i]);
    }

    return res;
}

int main()
{

    int arr[] = {3, 0, 1, 2, 5}, n = 5;

    cout << getWater(arr, n);
}
/*********************************************************************************************/

// Efficient Method

#include <iostream>
#include <cmath>
using namespace std;

int getWater(int arr[], int n)
{
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int res = 0;

        int lMax[n];
        int rMax[n];

        lMax[0] = arr[0];
        for (int i = 1; i < n; i++)
            lMax[i] = max(arr[i], lMax[i - 1]);

        rMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rMax[i] = max(arr[i], rMax[i + 1]);

        for (int i = 1; i < n - 1; i++)
            res = res + (min(lMax[i], rMax[i]) - arr[i]);

        return res;
    }

    return res;
}

int main()
{

    int arr[] = {5, 0, 6, 2, 3}, n = 5;

    cout << getWater(arr, n);
}
/*************************************************************************************************/
// Maximum consequtive one's in a binary array

#include <iostream>
#include <cmath>
using namespace std;

int maxConsecutiveOnes(int arr[], int n)
{
    int res = 0, curr = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            curr = 0;
        else
        {
            curr++;

            res = max(res, curr);
        }
    }

    return res;
}

int main()
{

    int arr[] = {0, 1, 1, 0, 1, 1, 1}, n = 7;

    cout << maxConsecutiveOnes(arr, n);
}
/*************************************************************************************/

// Maximum subarray sum

#include <iostream>
#include <cmath>
using namespace std;

int maxSum(int arr[], int n)
{
    int res = arr[0];

    int maxEnding = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);

        res = max(maxEnding, res);
    }

    return res;
}

int main()
{

    int arr[] = {1, -2, 3, -1, 2}, n = 5;

    cout << maxSum(arr, n);
}
/************************************************************************************************/

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