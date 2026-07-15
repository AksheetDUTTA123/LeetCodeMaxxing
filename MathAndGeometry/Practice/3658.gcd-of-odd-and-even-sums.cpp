#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3658 lang=cpp
 *
 * [3658] GCD of Odd and Even Sums
 */

// @lc code=start
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // int currOdd = 0;
        // int sumOdd = 1;
        // int currEven = 0;
        // int sumEven = 2;
        // for(int i = 1; i <= n; i++){
        //     currOdd += sumOdd;
        //     sumOdd += 2;
        //     currEven += sumEven;
        //     sumEven += 2;
        // }
        // cout << currOdd << std::endl;
        // cout << currEven;
        // return gcd(currOdd, currEven);

        //easier answer is to just return n, gcd of odd, even = (n^2, n(n+1))
        return n;
    }
};
// @lc code=end

