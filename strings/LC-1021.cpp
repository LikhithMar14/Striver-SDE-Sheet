#include<bits/stdc++.h>
using namespace std;

//Dont overthink in question clearly mentioned about the format the string will be compatible with opening and closing
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string str = "";

        for(auto &it : s){
            if(it == '('){
                //not an opening parenthesis
                if(cnt > 0)str += it;
                cnt++;
            }else {
                if(cnt > 1)str += it;
                cnt--;
            }
        }

        return str;
    }
};