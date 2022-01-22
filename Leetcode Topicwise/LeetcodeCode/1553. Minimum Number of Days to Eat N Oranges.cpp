class Solution {
public:
    int minDays(int n) {
        int res = 0;
        queue<int> q;
        unordered_set<int> visited;

        q.push(n);
        visited.insert(n);
        while(!q.empty()){
            
            int c = q.size();
            int curr;
            for(int i = 0; i<c; i++){
                curr = q.front();
                q.pop();
                if(curr == 0)
                    break;
                if(curr % 3 == 0){
                    int rem = curr - 2 * (curr / 3);
                    if(rem >= 0 && visited.find(rem) == visited.end()){
                        q.push(rem);
                        visited.insert(rem);
                    }
                }
                if(curr % 2 == 0){
                    int rem = curr - curr / 2;
                    if(rem >= 0  && visited.find(rem) == visited.end()){
                        q.push(rem);
                        visited.insert(rem);
                    }
                }
                int rem = curr - 1;
                if(visited.find(rem) == visited.end()){
                    q.push(rem);
                    visited.insert(rem);
                }
            }
            if(curr == 0)
                break;
            res++;
        }
        
        return res;
    }
};