#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>>a;
        int res = 1;
        
        for(int i=0; i < n; i++)a.push_back({start[i],end[i]});
        
        sort(a.begin(),a.end(),cmp);
        int lastEnd = a[0].second;
        
        for(int i=0; i < a.size(); i++){
            if(a[i].first > lastEnd){
                lastEnd = a[i].second;
                res++;
            }
                
        }
        return res;
        
        
    }
    
};