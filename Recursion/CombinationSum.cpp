#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int n,vector<int>&s,vector<vector<int>>&res, vector<int>&temp,int currSum,int target){
        if(currSum == target){
            res.push_back(temp);
            return;
        }
        if(currSum > target || i >= n){
            return;
        }

        temp.push_back(s[i]);
        solve(i,n,s,res,temp,currSum+s[i],target);
        temp.pop_back();


        solve(i+1,n,s,res,temp,currSum,target);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int n = candidates.size();
        solve(0,n,candidates,res,temp,0, target);
        return res;
    }
};