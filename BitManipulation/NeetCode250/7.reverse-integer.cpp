#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while (x != 0){
            int digit = x % 10;
            if(num > INT_MAX / 10 || (num == INT_MAX && digit > 7)) return 0; //if num is greater than INT_MAX / 10, then multiplying by 10 will cause an overflow, if num is equal to INT_MAX / 10, then we need to check if the digit is greater than 7, because INT_MAX is 2147483647, so if the digit is greater than 7, then we will overflow
            if (num < INT_MIN / 10 || (num == INT_MIN && digit < -8)) return 0; //if num is less than INT_MIN / 10, then multiplying by 10 will cause an underflow, if num is equal to INT_MIN / 10, then we need to check if the digit is less than -8, because INT_MIN is -2147483648, so if the digit is less than -8, then we will underflow
            num = num * 10 + digit;
            x /= 10;
        }
        return num;
    }
};
// @lc code=end

