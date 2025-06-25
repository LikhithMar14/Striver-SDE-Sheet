#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;

        int ans = 1e9;

        while(l <= h){
            int mid = l+ ((h-l) >> 1);
            //kisi ek side me ho
            if(nums[mid] >= nums[l]){
                ans = min(nums[l], ans);
                l = mid+1;

            }
            //you are on both sides
            else {
                ans = min(nums[mid],ans);
                h = mid-1;
            }
        }
        return ans;
    }
};