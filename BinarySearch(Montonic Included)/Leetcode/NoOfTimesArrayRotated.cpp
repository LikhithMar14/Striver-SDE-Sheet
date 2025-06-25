#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int l = 0;
        int h = nums.size() - 1;
        int maxVal = INT_MIN;
        int maxIndex = -1;
        int n = nums.size();

        while (l <= h) {
            int mid = l + ((h - l) >> 1);

            if (nums[mid] >= nums[l]) {
                if (nums[mid] > maxVal) {
                    maxVal = nums[mid];
                    maxIndex = mid;
                }
                l = mid + 1;
            } else {
                if (nums[h] > maxVal) {
                    maxVal = nums[h];
                    maxIndex = h;
                }
                h = mid - 1;
            }
        }

        return (n-(n-1-maxIndex));
    }
};
