class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        if(nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        
        for(int i = 0; i<nums.size(); i++){
            int n = nums[i];
            nums.erase(nums.begin() + i);
            vector<vector<int>> perms = permute(nums);

            for(auto perm : perms){
                perm.push_back(n);
                res.push_back(perm);
            }


            nums.insert(nums.begin() + i, n);
        }
        
        return res;
    }
};