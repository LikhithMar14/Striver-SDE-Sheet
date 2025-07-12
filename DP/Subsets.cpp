#include<bits/stdc++.h>
using namespace std;

//Target Sum

//Struggeld for direct tabluated aprpoach

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();    
        //state => the number of ways from index i we can reach a sum s
        //state defination dp[i][s]
        //transition equation dp[i][j] = addcodn+subcodn
        //addcondn = dp[i+1][sum+nums[i]]
        //subcondn = dp[i+1][sum-nums[i]]

        //amx sum we can cover is 2*target
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target) > sum)return 0;
        //Clear state defination dp[i][sum]
        // the number of ways that we acheive the sum from i->n-1

        vector<vector<int>>dp(n+3,vector<int>(2*sum+2,0));

        //we need off set to conver the negative indexs
        //max negative calue can be upto max(target)+maxS(sum)
        int offSet = sum;
        //base case right
        dp[n][offSet] = 1;

        for(int i=n-1; i >= 0; i--){
            for(int j=sum; j >= -1*sum; j--){


                int add = j + nums[i];
                int sub = j - nums[i];

                if (add + offSet < 2*sum+2)
                    dp[i][j + offSet] += dp[i + 1][add + offSet];

                if (sub + offSet >= 0)
                    dp[i][j + offSet] += dp[i + 1][sub + offSet];

            }
        }
        return dp[0][target+offSet];



    }
};

//parttion equal subset

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;

        //teh whole objective of us is to find atleast one way os that we can reach the
        //target of sum/2 from 0 to n-1;

        //the intgers are positive no change of getting anegatvei num

        int w = sum/2+2;
        int n = nums.size();

        vector<vector<int>>dp(n+2,vector<int>(w+2,0));
        dp[n][0] = 1;

        for(int i=n-1; i >= 0; i--){
            for(int j=sum/2; j >= 0; j--){
                dp[i][j] = (((j >= nums[i]) ? dp[i+1][j-nums[i]]:0) || dp[i+1][j]);
            }
        }
        return dp[0][sum/2];
    }
};