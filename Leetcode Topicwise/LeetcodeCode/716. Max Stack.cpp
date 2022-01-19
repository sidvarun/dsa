class MaxStack {
public:
    stack<pair<int, int>> s;
    MaxStack() {
        
    }
    
    void push(int x) {
        if(s.empty())
            s.push({x, x});
        else{
            int maxm = max(x, s.top().second);
            s.push({x, maxm});
        }
    }
    
    int pop() {
        if(!s.empty()){
            int val = s.top().first;
            s.pop();
            return val;
        }
        else 
            return -1;
    }
    
    int top() {
        return s.top().first;
    }
    
    int peekMax() {
        if(!s.empty())
            return s.top().second;
        else 
            return -1;
    }
    
    int popMax() {
        stack<pair<int, int>> st;
        int maxm = s.top().second;
        while(s.top().first != maxm){
            st.push(s.top());
            s.pop();
        }
        s.pop();
        while(!st.empty()){
            push(st.top().first);
            st.pop();
        }
        return maxm;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */