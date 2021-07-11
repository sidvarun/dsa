// N meetings in one room - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        int count;
        for(int i = 0; i<n; i++)
            v.push_back({end[i], start[i]});
        sort(v.begin(), v.end());
        count = 1;
        int posLast = 0;
        for(int i = 1; i<n; i++){
            if(v[i].second>v[posLast].first){
                count++;
                posLast = i;
            }
        }
        return count;
        
    }
};
/**************************************************************************************************/
// Fractional Knapsack - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
class Solution
{
    public:
    static bool myCmp(Item a, Item b)
    {
    	double r1 = (double)a.value / a.weight;
    
    	double r2 = (double)b.value / b.weight;
    
    	return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, myCmp);
        double res = 0.0;
        for(int i = 0; i<n; i++){
            if(arr[i].weight <= W){
                res = res + arr[i].value;
                W = W - arr[i].weight;
            }
            else{
                double val = W * ((double)arr[i].value/arr[i].weight);
                res = res + val;
                W = 0;
            }
        }
        return res;
        
    }
        
};
/***********************************************************************************************************/
// Job Sequencing Problem - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool myCmp(Job j1, Job j2){
        return j1.profit>j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> v;
        sort(arr, arr+n, myCmp);
        int res = 0;
        int count = 0;
        bool full[n] = {false};
        for(int i = 0; i<n; i++){
            for(int j = min(n, arr[i].dead) - 1; j>=0; j--){
                if(full[j] == false){
                    count++;
                    res += arr[i].profit;
                    full[j] = true;
                    break;
                }
            }
        }
        
        v.push_back(count);
        v.push_back(res);
        return v;
    } 
};
/***********************************************************************************************************/