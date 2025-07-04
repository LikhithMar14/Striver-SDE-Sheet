#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/trapping-rain-water/description/
//================================IMPORTANT================================================

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        stack<int> st; 

        for (int i = 0; i < n; i++) {

            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();
                cout<<"Entered on the cell"<<height[i]<<endl;

                if (st.empty()) break; 

                int left = st.top();
                int width = i - left - 1;
                int boundedHeight = min(height[i], height[left]) - height[bottom];

                res += width * boundedHeight;
            }

            st.push(i);
        }
        //onlhy push the when you find large emlemetn
        return res;
    }
};
