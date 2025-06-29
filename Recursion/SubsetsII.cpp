#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void solve(int i,int n,vector<vector<int>>&res,vector<int>&temp,vector<int>&s){
        res.push_back(temp);
        
        for(int j=i; j < n; j++){
            if(j > i && s[j] == s[j-1])continue;

            temp.push_back(s[j]);
            solve(j+1,n,res,temp,s);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //optimal approach
        sort(nums.begin(), nums.end()); 
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,nums.size(),res,temp,nums);
        return res;
        //unoptimal approach
        // set<vector<int>>st;
        // for(auto &it: res)st.insert(it);
        // // delete res;
        // vector<vector<int>> finalRes(st.begin(), st.end());
        // return finalRes;
    }
};