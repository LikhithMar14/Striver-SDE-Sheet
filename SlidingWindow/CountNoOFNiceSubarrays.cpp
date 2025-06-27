#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int>&arr){
        int i = 0;
        int j =0;
        int ans = 0;

        map<int,int>mp;

        while(j < n){
            mp[arr[j]%2]++;
            while(i <= j && mp[1] > k){
                mp[arr[i]%2]--;
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        return (solve(n,k,nums)-solve(n,k-1,nums));
    }
};