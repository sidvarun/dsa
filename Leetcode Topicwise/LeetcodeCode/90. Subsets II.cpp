class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i, vector<int> subSet, vector<int> nums){
        res.push_back(subSet);
        for(int k = i; k < nums.size(); k++){
            if(k > i && nums[k] == nums[k - 1])
                continue;
            subSet.push_back(nums[k]);
            dfs(k + 1, subSet, nums);
            subSet.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subSet;
        dfs(0, subSet, nums);
        return res;
    }
};