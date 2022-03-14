class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<string> d;
        queue<pair<int, string>> q;

        for(int i = 0; i<dominoes.size(); i++){
            string str = "";
            str += dominoes[i];
            if(str != ".")
                q.push({i, str});
            d.push_back(str);
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            string state = curr.second;
            
            if(state == "L"){
                if(i - 1 >= 0 && d[i - 1] == "."){
                    d[i - 1] = "L";
                    q.push({i - 1, "L"});
                }
            }
            else if(state == "R" && i + 1 < n && d[i + 1] == "."){
                if(i + 2 < n && d[i + 2] == "L"){
                    q.pop();
                }
                else{
                    d[i + 1] = "R";
                    q.push({i + 1, "R"});                    
                }
            }
        }
        
        string res = "";
        for(auto c : d)
            res += c;
        return res;
        
    }
};