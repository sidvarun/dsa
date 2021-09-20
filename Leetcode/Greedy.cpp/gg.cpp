class Solution {
public:
    bool isSafe(int i, int j, int m, int n){
        if(i >= m || i < 0 || j < 0 || j >= n)
            return false;
        return true;
    }
    void dfs(vector<vector<int>> land, vector<vector<int>> &visited, int i, int j, vector<int> &temp, int m, int n){
        visited[i][j] = 1;
        if(i == m - 1 && j == n - 1){
            temp.push_back(i);
            temp.push_back(j);
            return;
        }
        if(isSafe(i, j + 1, m, n) && land[i][j+1] == 0 && isSafe(i + 1, j, m, n) && land[i + 1][j] == 0){
            temp.push_back(i);
            temp.push_back(j);
            return;
        }
        if(isSafe(i + 1, j, m, n) && land[i + 1][j] == 0 && !isSafe(i, j + 1, m, n)){
            temp.push_back(i);
            temp.push_back(j);
            return;
        }
        if(isSafe(i , j + 1, m, n) && land[i][j + 1] == 0 && !isSafe(i + 1, j, m, n)){
            temp.push_back(i);
            temp.push_back(j);
            return;
        }
        
        if(isSafe(i, j + 1, m, n) && land[i][j+1] && !visited[i][j+1])
            dfs(land, visited, i, j + 1, temp, m, n);
        if(isSafe(i + 1, j, m, n) && land[i + 1][j] && !visited[i + 1][j])
            dfs(land, visited, i + 1, j, temp, m, n);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> res;
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(land[i][j] && !visited[i][j]){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    dfs(land, visited, i, j, temp, m, n);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = 0;
        for(int k = nums.size() - 1; k>=3; k--){
            int sum = nums[k];
            for(int i = 0; i<k-2; i++){
                int l = 0;
                int r = k - 1;
                while(l < r){
                    if(l == i){
                        l++;
                        continue;
                    }
                    else if(r == i){
                        r--;
                        continue;
                    }
                    else{
                        int currSum = nums[i] + nums[l] + nums[r];
                        if(currSum == sum){
                            c++;
                            l++;
                            r--;
                            while(l < nums.size() && nums[l] == nums[l - 1]){
                                l++;
                                c++;
                            }
                            while(l < r && nums[r] == nums[r + 1]){
                                r--;
                                c++;
                            }
                        }
                        else if(currSum > sum)
                            r--;
                        else
                            l++;
                    }
                    
                }
            }
        }
        return c;
    }
};