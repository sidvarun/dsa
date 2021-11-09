https://leetcode.com/problems/moving-average-from-data-stream/

class MovingAverage {
public:
    int s;
    int sum;
    queue<int> q;
    MovingAverage(int size) {
        s = size;
        sum = 0;
    }
    double next(int val) {
        if(q.size() == s){
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return (double) sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */