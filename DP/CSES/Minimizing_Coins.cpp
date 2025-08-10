#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int t;
    cin>>n>>t;
    vector<int>arr(n,0);
    for(int i=0; i < n; i++)cin>>arr[i];

    //state : dp[i] = min no of coins required to acheive t from i
    //transition: dp[i] = min(you can pick anyone in the array)
    //whne you are already at the target then the no of coins requrteid to reach teh target is 0
    
    vector<int>dp(t+1,INT_MAX);
    dp[t] = 0;


    for(int i=t-1; i >= 0; i--){
        for(int j=0; j < n; j++){
            if(i+arr[j] <= t && dp[i+arr[j]] != INT_MAX){
                dp[i] = min(dp[i],1+dp[i+arr[j]]);
            }
        }
    }
    if(dp[0] == INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[0]<<endl;
    }
}