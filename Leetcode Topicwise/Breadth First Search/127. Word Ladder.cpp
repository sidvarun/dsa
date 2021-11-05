https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(auto i : wordList)
            s.insert(i);
        s.insert(beginWord);
        if(s.find(endWord) == s.end())
            return 0;
        map<string, vector<string>> m;
        
        for(auto word : s){
            for(int j = 0; j<word.length(); j++){
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                m[pattern].push_back(word);
            }
        }
        
        unordered_set<string> visited;
        int res = 1;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        while(!q.empty()){
            int count = q.size();
            for(int k = 0; k<count; k++){
                string str = q.front();
                q.pop();
                if(str == endWord)
                    return res;

                for(int j = 0; j<str.length(); j++){
                    string pattern = str.substr(0, j) + "*" + str.substr(j + 1);
                    for(auto x : m[pattern]){
                        if(visited.find(x) == visited.end()){
                            q.push(x);
                            visited.insert(x);
                        }
                    }
                }  
            }
            res++;
        }
        return 0;
    } 
};
