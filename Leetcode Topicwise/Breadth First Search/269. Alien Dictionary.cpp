https://leetcode.com/problems/alien-dictionary/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> wordSet;
        for(auto w : words)
            for(auto c : w)
                wordSet.insert(c);
        unordered_map<char, unordered_set<char>> m;
        unordered_map<char, int> indegree;
        for(int i = 0; i<words.size(); i++){
            for(int j = i + 1; j<words.size(); j++){
                string word1 = words[i];
                string word2 = words[j];
                int p1 = 0; int p2 = 0;
                while(p1 < word1.length() && p2 < word2.length() && word1[p1] == word2[p2]){
                    p1++;
                    p2++;
                }
                if(p2 == word2.length() && p1 != word1.length())
                    return "";
                if(p1 == word1.length() || p2 == word2.length())
                    continue;
                if(m[word2[p2]].find(word1[p1]) != m[word2[p2]].end())
                    return "";
                if(m[word1[p1]].find(word2[p2]) == m[word1[p1]].end()){
                    m[word1[p1]].insert(word2[p2]);
                    indegree[word2[p2]]++;                    
                }
            }
        }

        queue<char> q;
        for(auto x : wordSet){
            if(indegree.find(x) == indegree.end())
                q.push(x);
        }
        string res = "";
        while(!q.empty()){
            char curr = q.front();
            q.pop();
            res += curr;
            for(auto x : m[curr]){
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        return res;
    }
};
