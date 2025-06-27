#include<bits/stdc++.h>
using namespace std;

//SO CALLED HARD LEETCODE QUESTION
class Solution {
public:

    int solve(int n, int k, vector<int>&nums){
        int i=0;
        int j=0;
        int ans = 0;

        map<int,int>mp;

        while(j < n){
            mp[nums[j]]++;
            while(i <= j && mp.size() > k){
                (mp[nums[i]] > 1) ? mp[nums[i]]-- : mp.erase(nums[i]);
                i++;
            }
            ans += (j-i+1);
            j++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return (solve(n, k,nums)-solve(n,k-1,nums));
    }
};