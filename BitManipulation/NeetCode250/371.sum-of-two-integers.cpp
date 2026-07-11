#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = a & b; //carry is the common set bits of a and b if 1 and 1, will carry to the next bit, 1 & 1 is 1
            a = a ^ b; //sum of bits of a and b where at least one of the bits is not set, 1 ^ 1 is 0, 1 ^ 0 is 1, 0 ^ 1 is 1, 0 ^ 0 is 0
            b = carry << 1; //carry is shifted by one so that adding it to a gives the required sum, we shift left because we want to add the carry to the next bit
        }

        return a;
    }
};
// @lc code=end

