class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        
        string res = "";
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(res.length() > 1 && res[res.length() - 1] == curr.second && res[res.length() - 2] == curr.second){
                if(pq.empty())
                    break;
                auto curr2 = pq.top();
                pq.pop();
                res += curr2.second;
                curr2.first -= 1;
                if(curr2.first > 0)
                    pq.push({curr2.first, curr2.second});
            }
            else{
                res += curr.second;
                curr.first -= 1;
            }
            if(curr.first > 0)
                pq.push({curr.first, curr.second});
        }
        return res;
    }
};