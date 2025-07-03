#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Higly used in cp when we need common intervals
        // Imagine on a graph then it will be intuitive

        int i = 0;
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> temp;

        int n = intervals.size();

        while (i < n && intervals[i][1] < left) {
            temp.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= right) {
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
            i++;
        }
        temp.push_back({left, right});

        while (i < n) {
            temp.push_back(intervals[i]);
            i++;
        }

        return temp;
    }
};
