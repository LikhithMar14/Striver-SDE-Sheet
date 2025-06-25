//Best way to solve this problem is draw a graph and plot the points see the pattern

//first find the mid

//check where is your does it exists on sorted portion or the unsorted portion

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;

        int ans = -1;

        while(l <= h) {
            int mid = l + ((h-l) >> 1);
            if(nums[mid] == target)return mid;

            //check where is your does it exists on sorted portion or the unsorted portion

            if(nums[l] <= nums[mid]){
                //sorted portion
                if(target >= nums[l] && target <= nums[mid]){
                    h = mid-1;
                }
                else l = mid+1;
            }else {
                //unsorted portion
                if(target >= nums[mid] && target <= nums[h]){
                    l = mid+1;
                }else h = mid-1;
            }
        }
        return -1;
    }
};