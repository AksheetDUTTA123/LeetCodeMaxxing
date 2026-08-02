#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        int newNum = 0;
        for(int i = 0; i < 32; i++){
            newNum = (newNum << 1) | (n & 1);
            n >>= 1;
        }
        return newNum;
    }
};
// @lc code=end

