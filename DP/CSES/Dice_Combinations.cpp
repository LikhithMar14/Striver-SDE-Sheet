#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    //state dp[i] = no of ways to acheive n from i
    //transition pick same element or pick other elemtn check for overflwo in both cases
    //base case dp[n-1] = 1

    vector<int>dp(n+1,0);
    dp[n] = 1;
    int MOD = 1e9+7;

    for(int i=n-1; i >= 0; i--){
        for(int j=1; j <= 6; j++){
            if(i+j <= n){
                dp[i] = (dp[i] + dp[i+j])%MOD;
            }
        }
    }
    cout<<dp[0]<<endl;
}