class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> list;
    int index;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end())
            return false;
        list.push_back(val);
        m[val] = list.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        int n = list.size();
        int pos = m[val];
        m[list[n - 1]] = pos;
        swap(list[n - 1], list[pos]);
        list.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int max = list.size() - 1;
        int min = 0;
        int range = max - min + 1;
        int num = rand() % range + min;
        
        return list[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */