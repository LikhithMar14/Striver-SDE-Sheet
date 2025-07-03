#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        int i = 1;
        int n  = intervals.size();
        int start = intervals[0][0];
        int index = intervals[0][1];

        sort(intervals.begin(), intervals.end());


        while(i < n){
            while(i < n && index >= intervals[i][0]){
                //you are in the valid index
                index = max(index,intervals[i][1]);
                i++;
            }
            if(i >= n)break;
            res.push_back({start,index});
            start = intervals[i][0];
            index = intervals[i][1];
            i++;

        }
        res.push_back({start,index});

        return res;
    }
};