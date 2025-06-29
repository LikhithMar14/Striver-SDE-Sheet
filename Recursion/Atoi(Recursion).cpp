#include<bits/stdc++.h>
using namespace std;
//is question ne fielding set kr dia
class Solution {
public:
    void solve(int start, int end, string &s, string &temp, bool &isPos, bool &isStarted) {
        if (start > end) return;

        if (s[start] == ' ' && !isStarted) {
            solve(start + 1, end, s, temp, isPos, isStarted);
            return;
        }

        if (s[start] == '-' && !isStarted) {
            isPos = false;
            isStarted = true;
            solve(start + 1, end, s, temp, isPos, isStarted);
            return;
        }

        if (s[start] == '+' && !isStarted) {
            isPos = true;
            isStarted = true;
            solve(start + 1, end, s, temp, isPos, isStarted);
            return;
        }

        if (isdigit(s[start])) {
            isStarted = true;
            temp.push_back(s[start]);
            solve(start + 1, end, s, temp, isPos, isStarted);
            return;
        }


        return;
    }

    int myAtoi(string s) {
        if (s.empty()) return 0;

        string temp = "";
        bool isPos = true;
        bool isStarted = false;
        solve(0, s.size() - 1, s, temp, isPos, isStarted);

        if (temp.empty()) return 0;
        
        long long num = 0;
        for (char c : temp) {
            int digit = c - '0';

            if (num > (LLONG_MAX - digit) / 10) {
                return isPos ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
        }

        if (!isPos) num = -num;

        if (num > INT_MAX) return INT_MAX;
        if (num < INT_MIN) return INT_MIN;

        return static_cast<int>(num);
    }
};
