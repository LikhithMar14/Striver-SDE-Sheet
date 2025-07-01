//Important Pattern 

#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        //wont work because * is not some magic , position matters
    //     stack<char>st;
    //     int starCnt = 0;
    //     for(int i=0; i < n; i++){
    //         if(s[i] == '(')st.push('(');
    //         else if(s[i] == '*')starCnt++;
    //         else{
    //             if(st.size()){
    //                 char topChar = st.top();
    //                 if(topChar == '(')st.pop();
    //             }
    //             else st.push(')');
    //         }
    //     }
    //     return st.size() <= starCnt;
    // }

        int l = 0;
        int h = 0;
        //if we choose an extra '(' l 
        //if we choose an extra ') h
        
        //the condition when string is not going to be valid

        for(char c : s){
            if(c == '('){
                l++;    // must add an open
                h++;    // could be open
            }
            else if(c == ')'){
                l--;    // close one '(' if any
                h--;    // close one '(' at most
            }
            else{ // '*'
                l--;    // if * is ')'
                h++;    // if * is '('
            }

            // We can't have more ')' than '(' at any point
            if(h < 0) return false;

            // l can't be negative (minimum open '(' can't go below 0)
            l = max(l, 0);
        }

        // at the end, if min open brackets can be zero, it's valid
        return l == 0;
    }
};