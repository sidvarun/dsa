https://leetcode.com/problems/grumpy-bookstore-owner/

https://leetcode.com/problems/grumpy-bookstore-owner/discuss/299230/JavaPython-3-Sliding-window.

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = customers.size();
        int sumInit = 0;
        int maxm = 0;

        for(int i = 0; i<n; i++)
            if(grumpy[i] == 0)
                sumInit += customers[i];
                    
        for(int i = 0; i<minutes; i++)
            if(grumpy[i] == 1)
                sum += customers[i];
        int i = 0;
        maxm = sum;
        for(int j = minutes; j<n; j++){
            if(grumpy[j] == 1 && grumpy[i] == 1)
                sum = sum + customers[j] - customers[i];
            else if(grumpy[j] == 1)
                sum = sum + customers[j];
            else if(grumpy[i] == 1)
                sum = sum - customers[i];
            maxm = max(maxm, sum);
            i++;
        }
        int res = 0;
        res = sumInit + maxm;
        return res;
    }
};
