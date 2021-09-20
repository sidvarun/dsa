#include<bits/stdc++.h>
using namespace std;
long long int solve(int n, int s, vector<int> stock, vector<int> price, vector<int> delivery){
    if(n == 0)
        return 0;
    if(s == 0)
        return INT_MAX;
    long long int res = INT_MAX;
    for(int i = 0; i<=stock[s - 1] && i<=n; i++){
        
        long long int temp = i * price[s - 1] + delivery[s - 1] + solve(n - i, s - 1, stock, price, delivery);
        if(temp<res)
            res = temp;
    }
    return res;
}

int main(){
    int n = 10;
    int s = 2;
    vector<int> stock = {5, 1000};
    vector<int> price = {5, 10};
    vector<int> delivery = {50, 0};
    long long int ans = solve(n, s, stock, price, delivery);
    cout<<ans;
    return 0;
}
if(i > 0)
             temp = temp + delivery[s - 1];

#include<bits/stdc++.h>
using namespace std;
long long int solve(int n, int s, vector<int> stock, vector<int> price, vector<int> delivery){
    if(n == 0)
        return 0;
    if(s == 0)
        return INT_MAX;
    long long int res = INT_MAX;
    for(int i = 0; i<=stock[s - 1] && i<=n; i++){
        
        long long int temp = i * price[s - 1] + delivery[s - 1] + solve(n - i, s - 1, stock, price, delivery);
        if(temp<res)
            res = temp;
    }
    return res;
}

int main(){
    int n = 20;
    int s = 4;
    vector<int> stock = {5, 10, 15, 20};
    vector<int> price = {5, 4, 6, 7};
    vector<int> delivery = {6, 12, 9, 0};
    long long int ans = solve(n, s, stock, price, delivery);
    cout<<ans;
    return 0;
}


int height(int n){
    queue<int> q;
    q.push(n);
    // q.push(0);
    int h = 0;
    while(!q.empty()){
        int count = q.size();
        for(int i = 0; i<q.size(); i++){
            int curr = q.top();
            q.pop();
            for(int i = 2; i<=curr/2; i++){
                if(curr%i == 0)
                    q.push(i);
            }
        }
        h++;
    }
    return h;
}