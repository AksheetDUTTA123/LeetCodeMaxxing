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
        int res = 0;
        for(int i = 0; i < 32; i++){
            res <<= 1; //shift result by 1 to the left, making room for the next bit
            res |= (n& 1); //get the rightmost bit of n and add it to the result
            n>>= 1; //discard right bit on n, look at new one
        }
        return res;
    }
};
// @lc code=end

