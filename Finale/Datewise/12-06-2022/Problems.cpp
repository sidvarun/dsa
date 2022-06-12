46. Permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;

        if(nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        
        for(int i = 0; i < nums.size(); i++){
            
            int num = nums[i];
            
            nums.erase(nums.begin() + i);
            
            vector<vector<int>> perms = permute(nums);
            
            for(auto perm : perms){
                perm.push_back(num);
                res.push_back(perm);
            }
            
            nums.insert(nums.begin() + i, num);
        }
        
        return res;
    }
};

/***********************************************************************************/

31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // 1. Find first i from right where nums[i] > nums[i - 1]
        // 2. Find first j from right where nums[j] > nums[i - 1]
        // 3. Swap nums[i - 1] & nums[j]
        // 4. nums.reverse(nums.begin() + i, nums.end())

        int n = nums.size();
        
        int i = n - 1;
        
       // 1. 
        while(i > 0 && nums[i - 1] >= nums[i])
            i -= 1;
        
       // i == 0 means nums is a decreasing array so next greater doesnt exist
        if(i == 0){
            sort(nums.begin(), nums.end());
            return;
        }
        
       // 2.
        int j = n - 1;
        
        while(j > i - 1 && nums[j] <= nums[i - 1])
            j -= 1;
        
        // 3.
        swap(nums[i - 1], nums[j]);
        
        // 4.
        reverse(nums.begin() + i, nums.end());
    }
};

/******************************************************************************************/

60. Permutation Sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> nums;
        
        string res = "";
        
        // store nos. 1 - n in the vector nums
        for(int i = 0; i < n; i++)
            nums.push_back(i + 1);
        
        k -= 1;
        int fact = 1;
        
        // find (n - 1)!
        for(int i = 1; i < nums.size(); i++)
            fact *= i;
       
        while(true){
            // find index of the block the kth permutation belongs to
            int index = k / fact;
                 
            // add first number of block to res
            res += to_string(nums[index]);
            
            // remove the added number from nums
            nums.erase(nums.begin() + index);
            
            if(nums.size() == 0)
                break;
            
            // now reduce the problem to finding the (k %  fact)th permutation in the updated nums vector
            k = k % fact;
            
            fact = fact / nums.size();
        }
        
        return res;
    }
};