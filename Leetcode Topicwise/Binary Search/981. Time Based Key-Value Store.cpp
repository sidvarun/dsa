https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> &arr = m[key];
        int l = 0;
        int r = arr.size() - 1;
        string res = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            int val = arr[mid].second;
            if(val <= timestamp){
                l = mid + 1;
                res = arr[mid].first;
            }
            else 
                r = mid - 1;
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