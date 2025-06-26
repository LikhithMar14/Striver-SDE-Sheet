//Really Good Question
//Failed to solve on First Attempt
//Good use of logic of even and odd postional change

//Editorial:https://algo.monster/liteproblems/single-element-in-sorted-array

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { 
        int n = nums.size();
        int l = 1;
        int h = n-2;

        if(n==1)return nums[0];

        if(nums[0] != nums[1])return nums[0];
        if(nums[n-1] != nums[n-2])return nums[n-1];

        //now we dont need worry about edge elemetns and for index out of bounds

        while(l <= h){
            int mid = (l + ((h-l) >> 1));
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])return nums[mid];
            //Odd Index
            if(mid%2){
                if(nums[mid] != nums[mid-1]){
                    //on the left
                    h = mid-1;
                }else l =mid+1;
            }else{
                if(nums[mid] != nums[mid+1]){
                    //on the left
                    h=mid-1;
                }else l = mid+1;
            }

        }
        return -1;


    }
};