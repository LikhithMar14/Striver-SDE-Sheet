#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());  

        int index = intervals[0][1]; 
        int i = 1;
        int n = intervals.size();
        int cnt = 0;  

        while (i < n) {
            while (i < n && intervals[i][0] < index) {
                cnt++;  
                index = min(index,intervals[i][1]);
                i++;
            }
            if(i >= n)break;
            index = intervals[i][1];
            i++;
            
        }

        return cnt;
    }
};
