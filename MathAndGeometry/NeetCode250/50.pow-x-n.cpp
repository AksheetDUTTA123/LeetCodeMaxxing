#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; //convert to long long to avoid overflow when n = INT_MIN
        if (N < 0){
            x = 1 / x;
            N = -N;
        }

        double res = 1.0;

        while(N > 0){
          if(N % 2 == 1){ //if N is odd, we multiply res by x and decrement N by 1 to make it even
            res *= x;
            N--;
          }
          N /=2; //if even, we can use fast power, so we divide N by 2 and square x, this way we can reduce the number of multiplications needed to compute x^n
          //ex, 2^8 = (2^2)^4 = 4^4 = (4^2)^2 = 16^2 = 256, so we can compute 2^8 in 3 multiplications instead of 7
          x *= x;
        }

        return res;
    }
};
// @lc code=end

