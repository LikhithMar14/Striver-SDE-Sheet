#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1,0);
    vector<int>dp(n+1,0);
    for(int i=0; i < n; i++){
        cin>>arr[i];
    }
    //state: 
    //dp[i] = maxiumum no of block i can get from this i
    //transition
    //dp[i] = max(dp[i+1],i+arr[i]+dp[i+1])
    
    //base case
    
    
    for(int i=n-1; i >= 0; i--){
        int pick = 0;
        if(arr[i]+i < n){
            pick = 1+arr[i];
            if(i+1+arr[i] < n){
                pick += dp[i+1+arr[i]];
            }
        }

        int skip += dp[i+1];
        
        dp[i] = max(pick,skip);
    }
    cout<<n-dp[0]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}