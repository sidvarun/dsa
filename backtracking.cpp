// Permutations of a given string - https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
class Solution
{
	public:
	    void generate(vector<string> &res, string str, int l, int r){
	        if(l == r)
	            res.push_back(str);
	        else{
	            for(int i = l; i<=r; i++){
	                swap(str[l], str[i]);
	                generate(res, str, l+1, r);
	                swap(str[l], str[i]);
	            }
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> res;
		    int n = s.length();
		    generate(res, s, 0, n-1);
		    sort(res.begin(), res.end());
		    return res;
		}
};
/********************************************************************************************************************/
// Rat in a Maze Problem I - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
class Solution{
    public:
    bool isSafe(int i, int j, int n){
        return (i<n && j<n && i>=0 && j>=0);
    }
    void findPathRec(vector<vector<int>> &m, int n, int i, int j, string str, vector<string> &res){
        if(i == n-1 && j == n-1){
            res.push_back(str);
            return;
        }
        m[i][j] = 0;
        if(isSafe(i+1, j, n) && m[i+1][j] == 1){
            findPathRec(m, n, i+1, j, str+"D", res);
        }
        if(isSafe(i, j-1, n) && m[i][j-1] == 1){
            findPathRec(m, n, i, j-1, str+"L", res);
        }
        if(isSafe(i, j+1, n) && m[i][j+1] == 1){
            findPathRec(m, n, i, j+1, str+"R", res);
        }
        if(isSafe(i-1, j, n) && m[i-1][j] == 1){
            findPathRec(m, n, i-1, j, str+"U", res);
        }
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string str = "";
        if(m[0][0] == 0){
            res.push_back("-1");
            return res;
        }
        findPathRec(m, n, 0, 0, str, res);
        sort(res.begin(), res.end());
        return res;
          
    }
};
/**********************************************************************************************************************/
// N-Queen Problem - https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1#

class Solution{
public:
    
    bool isSafe(int row, int col, vector<vector<int>> &board){
        for(int i=0; i<col; i++)
            if(board[row][i] == 1)
                return false;
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
            if(board[i][j] == 1)
                return false;
        for(int i=row, j=col; i<board.size() && j>=0; i++, j--)
            if(board[i][j] == 1)
                return false;
        return true;
    }
    void nQueenRec(int n, vector<vector<int>> &res, int col, vector<vector<int>> &board){
        if(col == n){
            vector<int> v;
            for(int j = 0; j<n; j++){
                for(int i = 0; i<n; i++){
                    if(board[j][i] == 1)
                        v.push_back(i+1);
                }
            }
            res.push_back(v);
        }
        for(int i = 0; i<n; i++){
            if(isSafe(i, col, board)){
                board[i][col] = 1;
                nQueenRec(n, res, col+1, board);
                board[i][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<vector<int>> res;
        nQueenRec(n, res, 0, board);
        sort(res.begin(), res.end());
        return res;
    }
};
/**************************************************************************************************/