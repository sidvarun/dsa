class Solution {
public:
    void pascalRec(int i, int rowIndex, vector<int>& prevRow){
        vector<int> currRow;
        for(int j = 0; j<=i; j++){
            if(j == 0 || j == i)
                currRow.push_back(1);
            else 
                currRow.push_back(prevRow[j - 1] + prevRow[j]);
        }
        prevRow = currRow;
        if(i == rowIndex)
            return;
        pascalRec(i + 1, rowIndex, prevRow);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> prevRow;
        pascalRec(0, rowIndex, prevRow);
        return prevRow;
    }
};