#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    //state dp[i][j] = the minium number of operations required to make the string from i and j to the ends same
    //insertion and delteion are same so we can just consider one thing and move forward
    //transtion => we have three otpions 
    // if same dp[i][j] = dp[i+1][j+1]
    //replacement dp[i][j] = dp[i+1][j+1]+1
    //deletion dp[i][j] = dp[i+1][j]+1
    //insertion dp[i][j] = dp[i][j+1]+1

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0; i < n; i++)dp[i][m] = n-i;
    for(int i=0; i < m; i++)dp[n][i] = m-i;

    for(int i=n-1; i >= 0; i--){
        for(int j=m-1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                dp[i][j] = min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]))+1;
            }
        }
    }
    cout<<dp[0][0]<<endl;
}