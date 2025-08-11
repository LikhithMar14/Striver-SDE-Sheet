#include<bits/stdc++.h>
using namespace std;

int main(){
    //state dp[i][k] = no of subsequnces you have from 1 to n such that k is the last digit chosen

    ///transtion will be you can make a valid thing with k and multiples of k
    // dp[i][j] = dp[i][j+(j+k)+(j+2k)+...+(j+nk)]

    int n,k;
    cin>>n>>k;

    //base case:
    vector<vector<int>>dp(k+1,vector<int>(n+1,0));
    int mod=1e9+7;
    for(int i=1; i <= n; i++)dp[k][i] = 1;

    for(int i=k-1; i >= 0; i--){
        for(int j=1; j <= n; j++){
            for(int x=j; x <= n; x+=j){
                dp[i][j] = (dp[i][j] + dp[i+1][x])%mod;
            }
        }
    }
    cout<<dp[0][1]<<endl;



}