#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0; i < n; i++){
        string temp;
        cin>>temp;
        arr[i] = temp;
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    if(arr[0][0] == '*' || arr[n-1][n-1] == '*'){
        cout<<0<<endl;
        return 0;
    }

    dp[n-1][n-1] = 1;
    int mod = 1e9+7;
    for(int i=n-1; i >= 0; i--){
        for(int j=n-1; j >= 0; j--){
            if(i == n-1 && j == n-1 || arr[i][j] == '*')continue;
            int pick = 0;
            if(i+1 < n){
                pick += dp[i+1][j];
            }
            if(j+1 < n){
                pick += dp[i][j+1];
            }
            dp[i][j] = pick;
            dp[i][j] %= mod;
        }   
    }
    cout<<dp[0][0]<<endl;
}