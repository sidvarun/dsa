https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0, m, n))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int count, int m, int n){
        if(count == word.length())
            return true;
        if(i<0 || i>= m || j<0 || j>=n || board[i][j] != word[count])
            return false;
        char temp = board[i][j];
        board[i][j] = '*';
        bool found = dfs(board, word, i + 1, j, count + 1, m, n) || dfs(board, word, i - 1, j, count + 1, m, n) || dfs(board, word, i , j + 1, count + 1, m, n) || dfs(board, word, i, j - 1, count + 1, m, n);
        board[i][j] = temp;
        return found;
    }
};