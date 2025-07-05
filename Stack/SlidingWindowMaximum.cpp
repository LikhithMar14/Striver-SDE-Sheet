#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // sliding window + monotonic queue
        deque<int> q; 
        vector<int> res;
        int n = nums.size();

        //k elements
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i); 
        }
        res.push_back(nums[q.front()]); 
        // Process the rest of the elements
        for (int i = k; i < n; i++) {

            if (!q.empty() && q.front() <= i - k) q.pop_front();

            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);

            res.push_back(nums[q.front()]);
        }

        return res;
    }
};
