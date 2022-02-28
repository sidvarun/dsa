class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        for(auto target : vector<int>{tops[0], bottoms[0]}){
            int missingT = 0;
            int missingB = 0;
            for(int i = 0; i<tops.size(); i++){
                int top = tops[i];
                int bottom = bottoms[i];
                
                if(top != target && bottom != target)
                    break;
                if(top != target)
                    missingT += 1;
                if(bottom != target)
                    missingB += 1;
                if(i == (tops.size() - 1))
                    return min(missingT, missingB);
            }
        }
        return -1;
    }
};