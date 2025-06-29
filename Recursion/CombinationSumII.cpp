#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, vector<int>&s, vector<vector<int>>&res,vector<int>&temp,int currSum,int target,int n){
        //in this question COMBINATION SUM  II there is no need to take duplicate

        //important prune case
        if(currSum > target)return;


        if(currSum == target){
            res.push_back(temp);
            return;
        }

        //fine-grained control

        for(int j=i; j < n; j++){
            //just prune it will result in same recursion tree
            if(j > i && s[j] == s[j-1])continue;

            temp.push_back(s[j]);
            solve(j+1,s,res,temp,currSum+s[j],target,n);
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& s, int target) {
        sort(s.begin(),s.end());
        vector<vector<int>>res;
        vector<int>temp;

        int n = s.size();

        solve(0,s,res,temp,0,target,n);
        return res;
    }
};