#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int firstNum = 0;
        int secondNum = 1;
        int currSum = 0;
        for(int i = 2; i <= n; i++){
            currSum = firstNum + secondNum;
            firstNum = secondNum;
            secondNum = currSum;
        }
        return currSum;
    }
};
// @lc code=end

