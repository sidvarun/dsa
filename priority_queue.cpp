// k largest elements -  https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> res;
	    priority_queue<int, vector<int>, greater<int> > pq;
	    for(int i = 0; i<k; i++)
	        pq.push(arr[i]);
	    for(int i = k; i<n; i++){
	        if(arr[i]>pq.top()){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    while(pq.empty() == false){
	        res.push_back(pq.top());
	        pq.pop();
	    }
	    reverse(res.begin(), res.end());
	    return res;
	}

};
/****************************************************************************************************/
// minimum sum - https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#
class Solution
{   
    string findSum(string X, string Y) 
    {
        int i = X.size() - 1, j = Y.size() - 1;
        
        string res = "";
        
        int carry = 0;
        while(i >= 0 and j >= 0)
        {
            int digit1 = X[i] - '0';
            int digit2 = Y[j] - '0';
            
            int cal = (digit1 + digit2 + carry) % 10;
            carry = (digit1 + digit2 + carry) / 10;
            
            res = to_string(cal) + res;
            
            i--;
            j--;
        }
        
        while(i >= 0)
        {
            int digit1 = X[i] - '0';
            
            int cal = (digit1 + carry) % 10;
            carry = (digit1 + carry) / 10;
            
            res = to_string(cal) + res;
            
            i--;
        }
        
        while(j >= 0)
        {
            int digit2 = Y[j] - '0';
            
            int cal = (digit2 + carry) % 10;
            carry = (digit2 + carry) / 10;
            
            res = to_string(cal) + res;
            
            j--;
        }
        
        if(carry != 0)
        {
            res = to_string(carry) + res;
        }
        
        for(int i = 0; i < res.size(); i++)
        {
            if(res[i] != '0')
            {
                return res.substr(i);
            }
        }
        
        return "0";
    }
    
    public:
    string solve(int arr[], int n)
    {
        sort(arr, arr + n);
        
        string num1, num2;
        for(int i = 0; i < n; i++)
        {
            
            if(i % 2 == 0)
            {
                num1 += to_string(arr[i]);
            }
            else
            {
                num2 += to_string(arr[i]);
            }
        }
        
        return findSum(num1, num2);
    }
};
/***************************************************************************************************************/
// Minimum Cost of ropes - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
         priority_queue<long long, vector<long long>, greater<long long> > pq(arr, arr + n);
         long long res = 0;
         while(pq.size() > 1){
             long long m1 = pq.top();
             pq.pop();
             long long m2 = pq.top();
             pq.pop();
             res += m1+m2;
             pq.push(m1+m2);
         }
        
         return res;
    }
};
/****************************************************************************************************************/