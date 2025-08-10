#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n,0);
    for(int i=0; i < n; i++)cin>>arr[i];

    //state
    //dp[i] = no of ways to acheive k from i to k 
    //what can we pick form the coins 
    int mod = 1e9+7;

    vector<int>dp(k+1,0);
    dp[k]=1;

    for(int i=k-1; i >= 0; i--){
        int pick = 0;
        for(int j=0; j < n; j++){
            if(i+arr[j] <= k){
                pick += dp[i+arr[j]];
                pick %= mod;
            }
            dp[i] = pick;
        }
    }
    cout<<dp[0]<<endl;
}