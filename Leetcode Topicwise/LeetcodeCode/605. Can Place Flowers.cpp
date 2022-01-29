class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // assume 0 before the start and after the end of the array;
        // so [1, 0, 0, 0, 1] changes to 0[1, 0, 0, 0, 1]0 -> [0, 1, 0, 0, 0, 1, 0]
        int num = flowerbed.size();
        vector<int> flower(num + 2, 0);
        for(int i = 1; i<=num; i++)
            flower[i] = flowerbed[i - 1];
        
        int res = 0;
        
        for(int i = 1; i<=num; i++){
            if(flower[i] == 0 && flower[i - 1] == 0 && flower[i + 1] == 0){
                flower[i] = 1;
                res++;
            }
        }
        return res >= n;
    }
};