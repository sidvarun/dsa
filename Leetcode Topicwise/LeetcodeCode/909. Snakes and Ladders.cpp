class Solution {
public:
    int n;
    vector<int> getCoordinates(int square){
        int r = (square - 1) / n;
        int c = (square - 1) % n;
        
        if(r % 2 != 0)
            c = n - 1 - c;
        
        return vector<int>{r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        reverse(board.begin(), board.end());
        
        queue<int> q;
        unordered_set<int> visited;
        
        q.push(1);
        visited.insert(1);
        
        int res = 0;
        
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int curr = q.front();
                q.pop();
                if(curr == n*n)
                    return res;
                
                for(int i = 1; i<=6; i++){
                    vector<int> coordinates = getCoordinates(curr + i);
                    int row = coordinates[0];
                    int col = coordinates[1];
                    if(row < n && visited.find(curr + i) == visited.end()){
                        if(board[row][col] != -1)
                            q.push(board[row][col]);
                        else
                            q.push(curr + i);
                        visited.insert(curr + i);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};