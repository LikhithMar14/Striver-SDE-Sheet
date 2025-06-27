#include<bits/stdc++.h>
using namespace std;

// Good question to learn substring and stack

class Solution {
public:
    string reverseWords(string s) {
        //trim 
        int n = s.size();
        int l = 0;
        int h = n-1;
        while(l < n && s[l] == ' ')l++;
        while(h >= 0 && s[h] == ' ')h--;

        if(l > h)return "";
        s = s.substr(l,h-l+1);

        cout<<s<<endl;
        stack<string>st;
        string ans = "";

        n = s.size();
        int j = 0;


        for(int i=0; i <= h; i++){
            if( i < n && s[i] == ' '){
                st.push(s.substr(j,i-j));
                while(i < n && s[i] == ' ')i++;
                j=i;
            }
        }
        st.push(s.substr(j,n-j));
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty())ans += ' ';
        }
        return ans;


        
    }
};