class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        val = v;
        prev = next = NULL;
    }
};
class LRUCache {
public:
    int size;
    Node* left = new Node(0, 0);
    Node* right = new Node(0, 0);
    unordered_map<int, Node*> cache;
    void remove(Node* node){
        Node* pre = node->prev;
        Node* nex = node->next;
        pre->next = nex;
        nex->prev = pre;
    }
    
    void insert(Node* node){
        Node* pre = right->prev;
        pre->next = node;
        node->prev = pre;
        node->next = right;
        right->prev = node;
    }
    LRUCache(int capacity) {
        size = capacity;
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            int value = cache[key]->val;
            remove(cache[key]);
            insert(cache[key]);
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        if(cache.size() > size){
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */