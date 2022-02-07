class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // unordered_set<int> s;
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();
        vector<long long> pow(n);
        pow[0] = 1;
        for(int i = 1; i<n; i++)
            pow[i] = (pow[i - 1] * 2) % 1000000007;
        
        int l = 0;
        int r = n - 1;
        
        while(l <= r){
            if(nums[l] + nums[r] > target)
                r--;
            else if(nums[l] + nums[r] <= target){
                res = (res + pow[r - l]) % 1000000007;
                l++;
            }
        }
        return res;
    }
};

/*
Explanation for solution:

For each l, move r left until you find the rightmost r that "works" for that l (A[l] + A[r] <= target).

Once you find a valid r for your l, you need to add this number of subsequences to ans.

All of these subsequences will contain l. So you don't need to worry about that. You need to count the number of subsequences in the array from l+1 to r including the empty subsequence! You include the empty subsequence because l on its own is a valid subsequence, so you can combine it with an empty subsequence and still have a valid subsequence.

For example:

A = [3, 5, 6], target = 9
l = 0, r = 2
A[l] + A[r] is equal to target, so we need to add this number of subsequences.
Remember, this set of subsequences will include 3. It can also include any of subsequences of [5, 6], which are [5], [6], [5, 6], and []. That is 4 subsequences, which equals 2^2, or 2^(r-1)

Then we check the rest of the array:

l = 1, r =2
A[l] + A[r]  > target, so r -= 1
l = 2, r =2
A[l] + A[r]  > target, so r -= 1
Finish, with ans = 4
*/