#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int i,int k,int target,vector<vector<int>>&res,vector<int>&temp,int n,int currSum,vector<int>&s){
        if(currSum > target || temp.size() > k)return;
        if(currSum == target && temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(i == n)return;

        temp.push_back(s[i]);
        solve(i+1,k,target,res,temp,n,currSum+s[i],s);
        temp.pop_back();

        solve(i+1,k,target,res,temp,n,currSum,s);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        if(target < 1)return {{}};

        vector<int>arr;
        for(int i=1; i <= 9; i++)arr.push_back(i);

        vector<vector<int>>res;
        vector<int>temp;
        int n = arr.size();

        solve(0,k,target,res,temp,n,0,arr);
        return res;
        
    }
};