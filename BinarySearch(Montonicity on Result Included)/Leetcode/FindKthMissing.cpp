#include<bits/stdc++.h>
using namespace std;
//not able to solve by own in logn
//Inuttion is to find the both borders
//
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int h = n-1;

        int ans = -1;

        while(l <= h) {
            int mid = (l+ ((h-l) >> 1));
            if((arr[mid]-1-mid) >= k){
                //you are on the right side
                h = mid-1;
            }else l = mid+1;
        }
        return h+k+1;
    }
};