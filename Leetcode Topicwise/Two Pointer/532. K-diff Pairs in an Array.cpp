https://leetcode.com/problems/k-diff-pairs-in-an-array/

https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/100135/JavaPython-Easy-Understood-Solution

class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.put(x, cnt.getOrDefault(x, 0) + 1);
        }
        int res = 0;
        for (int x : cnt.keySet()) {
            if ((k > 0 && cnt.containsKey(x + k)) || (k == 0 && cnt.get(x) > 1)) {
                res++;
            }
        }
        return res;
    }
}
/**************************************************/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto num:nums)
            map[num]++;
        
        int res = 0;
        if (k > 0) {
            for(auto a:map)
                if (map.find(a.first+k) != map.end()) 
                    res++;
        }
        
        else {
            for(auto a:map)
                if (a.second > 1)
                    res++;
        }
        
        return res;
    }
};