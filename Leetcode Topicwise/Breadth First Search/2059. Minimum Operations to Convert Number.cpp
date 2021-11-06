https://leetcode.com/problems/minimum-operations-to-convert-number/

https://leetcode.com/problems/minimum-operations-to-convert-number/discuss/1549960/C%2B%2B-or-BFS-or-Clean-code

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if(start == goal)
            return 0;
        int res = 0;
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i<size; i++){
                int curr = q.front();
                q.pop();
                if(curr == goal)
                    return res;
                if(curr > 1000 || curr < 0 || visited.find(curr) != visited.end())
                    continue;
                visited.insert(curr);
                for(int j = 0; j<nums.size(); j++){
                    int x = nums[j];
                    q.push(curr + x);
                    q.push(curr - x);
                    q.push(curr ^ x);
                }
            }
            res++;
        }
        return -1;
    }
};