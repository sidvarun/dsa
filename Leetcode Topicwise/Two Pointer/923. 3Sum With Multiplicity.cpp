923. 3Sum With Multiplicity

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9+7;
        int prev;
        long ans=0;
        int n=arr.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
            freq[arr[i]]++;       
        sort(arr.begin(),arr.end());
        int i=0;
        while(i<n)
        {
           int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>target)
                    k--;
                else if(sum<target)
                    j++;
                else
                {
                    //All Are Same
                    if(arr[i]==arr[j] && arr[j]==arr[k])
                    {
                        long count=freq[arr[i]];
                        
                        count=(count)*(count-1)*(count-2)/6;
                        count%=mod;
                        ans=(ans+count)%mod;                        
                    }
                    //All are different
                    else if(arr[i]!=arr[j] &&arr[j]!=arr[k] && arr[i]!=arr[k])
                    {
                        long count=(((freq[arr[i]]%mod)*(freq[arr[j]]%mod))%mod)*freq[arr[k]]%mod;
                        count%=mod;
                        ans+=count;
                    }
                    // 2 are of same
                    else
                    {
                        if(arr[i]==arr[j])
                        {
                            
                            long count=(freq[arr[i]]*(freq[arr[i]]-1)/2)%mod;
                            count=(count*freq[arr[k]])%mod;
                            ans+=count;
                        }
                        else if(arr[i]==arr[k])
                        {
                             long count=(freq[arr[i]]*(freq[arr[i]]-1)/2)%mod;
                            count=(count*freq[arr[j]])%mod;
                            ans+=count; 
                        }
                        else
                        {
                             long count=(freq[arr[j]]*(freq[arr[j]]-1)/2)%mod;
                            count=(count*freq[arr[i]])%mod;
                            ans+=count; 
                        }
                    }
                    j++;
                    while(j<k && arr[j]==arr[j-1])
                    j++;
                    ans%=mod;
                } 
            }
            i++;
            while(i<n && arr[i]==arr[i-1])
                i++;
            
        }
        return ans;
    }
};