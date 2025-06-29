#include<bits/stdc++.h>
using namespace std;
//Simple Binary Exponentiation
class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) return 1.0 / solve(x, -n);

        double half = solve(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }

    double myPow(double x, int n) {
        return solve(x, static_cast<long long>(n));  
    }
};
