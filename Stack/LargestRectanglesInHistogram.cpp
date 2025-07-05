#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//================================IMPORTANT================================================
//we are using a stack to store the indices of the elements
//we are using a leftMin and rightMin array to store the nearest smaller element on the left and right
//we are using a stack to store the indices of the elements
class Solution {
public:
    void findLeftMin(int n,vector<int>&heights, vector<int>&leftMin){
        stack<int>st;
        for(int i=0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()])st.pop();
            if(!st.empty())leftMin[i] = st.top();
            st.push(i);
        }
    }

    void findRightMin(int n,vector<int>&heights,vector<int>&rightMin){
        
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()])st.pop();
            if(!st.empty())rightMin[i] = st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        //continousou seris of elememt such that it is greater thatn or eaul to me
        //for every element find the nearest less than elelment on left side [left boundary]
        //[right boundary]

        int n = heights.size();
        vector<int>leftMin(n,-1);
        vector<int>rightMin(n,n);

        findLeftMin(n,heights,leftMin);
        findRightMin(n,heights,rightMin);

        int res = 0;
        // for(auto &it: leftMin)cout<<it<<" ";
        // cout<<endl;
        // for(auto &it: rightMin)cout<<it<<" ";
        // cout<<endl;

        //cout takes huge time 

        for(int i=0; i < n; i++){
            int dist = rightMin[i]-leftMin[i]-1;
            // cout<<dist<<endl;
            res = max(res,dist*heights[i]);
        }
        return res;

    }
};