#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>arr(n,0);
    for(int i=0; i < n; i++)cin>>arr[i];

    //state dp[i][k] = no of ways to chose coins from i to n-1 to make the sum k
    //transition you have two options at a coin you can skip it or take it
    //our main goal is to avoid the duplicate leements when sorted , we will achevei this using picking in a order
    //transition = dp[i][k-arr[i]]+dp[i+1][k]

    //base case = if we our k=0 at any point then we got a way to make the sum


    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    int mod = 1e9+7;
    for(int i=0; i < n; i++)dp[i][0]=1;
    //our loop will be we need previous k values and next i values
    //so in the first loop we will come from n-1 -> 0 and next we will go from 0 to k and our answer will be in dp[0][k]

    for(int i=n-1; i >= 0; i--){
        for(int j=1; j <= k; j++){
            int skip = dp[i+1][j];
            int pick = 0;
            if(j-arr[i] >= 0){
                pick = dp[i][j-arr[i]];
            }
            dp[i][j] = (skip+pick)%mod; 
        }
    }
    cout<<dp[0][k]<<endl;
}