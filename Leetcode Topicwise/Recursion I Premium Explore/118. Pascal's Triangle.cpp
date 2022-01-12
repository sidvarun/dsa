class Solution {
public:
    void pascalRec(int i, int numRows, vector<vector<int>>& res){
        if(i == numRows)
            return;
        vector<int> temp;
        for(int j = 0; j<=i; j++){
            if(j == 0 || j == i){
                temp.push_back(1);
            }
            else
                temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
        res.push_back(temp);
        pascalRec(i + 1, numRows, res);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        pascalRec(0, numRows, res);
        return res;
    }
};