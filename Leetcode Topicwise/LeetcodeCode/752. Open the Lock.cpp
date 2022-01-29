class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        string ref = "0123456789";
        unordered_set<string> dead;
        unordered_set<string> visited;
        for(auto s : deadends)
            dead.insert(s);
        
        if(dead.find("0000") != dead.end())
            return -1;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        
        int res = 0;
        
        while(!q.empty()){
            int c = q.size();
            
            while(c--){
                string curr = q.front();
                q.pop();
                if(curr == target)
                    return res;
                if(dead.find(curr) != dead.end())
                    continue;
                for(int i = 0; i<curr.length(); i++){
                    
                    string choice1 = "";
                    if(i != 0)
                        choice1 += curr.substr(0, i);
                    choice1.push_back(ref[(curr[i] - '0' + 1) % 10]);
                    if(i != curr.length() - 1)
                        choice1 += curr.substr(i + 1);
                    
                    if(visited.find(choice1) == visited.end()){
                        visited.insert(choice1);
                        q.push(choice1);
                    }
                    string choice2 = "";
                    if(i != 0)
                        choice2 += curr.substr(0, i);
                    choice2.push_back(ref[(curr[i] - '0' - 1) % 10 >= 0 ? (curr[i] - '0' - 1) % 10 : (curr[i] - '0' - 1) % 10 + 10]);
                    if(i != curr.length() - 1)
                        choice2 += curr.substr(i + 1);
                    
                    if(visited.find(choice2) == visited.end()){
                        visited.insert(choice2);
                        q.push(choice2);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};