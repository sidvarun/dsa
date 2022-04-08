class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end())
            return "";
        
        vector<pair<string, int>> &nums = m[key];
        
        int l = 0;
        int r = nums.size() - 1;
        
        string res = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(nums[mid].second > timestamp)
                r = mid - 1;
            
            else{
                res = nums[mid].first;
                l = mid + 1;
            }
        }
        
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */