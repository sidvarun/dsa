Intuition
The first and the last house can be one of the furthest houses.


Complexity
Time O(n)
Space O(1)


Solution 1
Find the last house with different color of the fisrt house.
Find the first house with different color of the last house.
Return the max distance of these two options.

 int maxDistance(vector<int>& A) {
        int n = A.size(), i = 0, j = n - 1;
        while (A[0] == A[j]) j--;
        while (A[n - 1] == A[i]) i++;
        return max(n - 1 - i, j);
    }