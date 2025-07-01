#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
  
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (dividend == divisor)
            return 1;

        bool isPos = (dividend >= 0) == (divisor >= 0);

      
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        int ans = 0;

        while (n >= d) {
            int i = 0;
            while (n >= (d << (i + 1))) {
                i++;
            }
            ans += (1 << i);       
            n -= (d << i);        
        }

        return isPos ? ans : -ans;
    }
};
