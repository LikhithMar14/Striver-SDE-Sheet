#include<bits/stdc++.h>
using namespace std;
//Dp approach
class Solution {
public:
    int solve(int index, int n,vector<int>&nums,vector<int>&dp){
        if(index < n && dp[index] != -1)return dp[index];
        if(index == n-1)return dp[index]=0;
        if(index >= n)return  INT_MAX;
        int mini = INT_MAX;
        for(int i=1; i <= nums[index]; i++){
            int temp = solve(index+i,n,nums,dp);
            if(temp != INT_MAX)mini = min(temp+1,mini);

        }
        return dp[index] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0,n,nums,dp);
    }
};