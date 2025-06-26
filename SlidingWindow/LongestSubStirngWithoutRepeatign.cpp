#include<bits/stdc++.h>
using namespace std;

//Good Segment Pattern
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        set<char>st;
        int ans = 0;
        int n = s.size();


        while(j < n) {
            //Good Segment Problem
            st.insert(s[j]);

            //shrinking condition
            while(st.size() < j-i+1){
                st.erase(s[i]);
                i++;
            }

            //checking answer
            ans = max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};