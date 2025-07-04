#include <bits/stdc++.h>
using namespace std;

//Monotonic Stack is a stack that maintains a monotonic order of elements.

//Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //Monotonic Stack
        vector<int>temp(1e4+5,0);
        stack<int>st;
        int n = nums2.size();

        for(int i = n-1; i >= 0; i--){
            //Monotonic Increasing Stack(fromn top to bottom)
            while(i >= 0 &&  st.size() > 0 && nums2[i] >= st.top())st.pop();
            if(st.empty()){
                temp[nums2[i]] = -1;

            }else{
                int el = st.top();
                temp[nums2[i]] = el;
            }
            st.push(nums2[i]);
         

        }

        vector<int>res;
        for(int i=0; i < nums1.size(); i++)res.push_back(temp[nums1[i]]);
        return res;

    }
};