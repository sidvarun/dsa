class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {        
        
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        int i = 0;
        int j = n - 1;
        
        int res = 0;
        
        while(i <= j){
            int rem = limit - people[j];
            res++;
            j--;
            
            if(i <= j && rem >= people[i])
                i++;
        }
        
        return res;
    }
};