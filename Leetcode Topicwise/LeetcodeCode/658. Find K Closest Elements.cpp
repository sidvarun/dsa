class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = arr.size() - 1;
        
        while(left < right){
            int mid = (right - left) / 2 + left;
            
            if(arr[mid] >= x)
                right = mid;
            else
                left = mid + 1;
        }
        
        left -= 1;

        right = left + 1;
        
        vector<int> res;
        
        while(right - left - 1 < k){
            if(left < 0)
                right += 1;
            else if(right == n)
                left -= 1;
            
            else if(abs(arr[left] - x) <= abs(arr[right] - x))
                left -= 1;
            else
                right += 1;
        }
        
        for(int i = left + 1; i<right; i++)
            res.push_back(arr[i]);
        
        return res;
    }
};




/************************************************************************/

Less Efficient Heap Solution

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for(int i = 0; i<arr.size(); i++)
            pq.push(vector<int>{abs(arr[i] - x), i});
        
        vector<int> res;
        unordered_set<int> closest;
        while(k && !pq.empty()){
            auto curr = pq.top();
            pq.pop();
            // if(closest.find(curr[0]) != closest.end())
            //     continue;
            // closest.insert(curr[0]);
            res.push_back(arr[curr[1]]);
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
