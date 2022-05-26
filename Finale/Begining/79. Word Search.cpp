class Solution {
public:
    string ref;
    int m;
    int n;
    
    bool dfs(vector<vector<char>>& board, int i, int j, int k, vector<vector<int>>& directions){
        
        if(k >= ref.length())
            return true;
        
        if(i >= m || i < 0 || j >= n || j < 0 || board[i][j] == '*' || board[i][j] != ref[k])
            return false;
    
        char temp = board[i][j];
        
        board[i][j] = '*';
        
        for(auto &dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            
            if(dfs(board, x, y, k + 1, directions))
                return true;
        }        
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        ref = word;
        vector<vector<int>> directions = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                if(dfs(board, i, j, 0, directions))
                    return true;
        }
        return false;
    }
};