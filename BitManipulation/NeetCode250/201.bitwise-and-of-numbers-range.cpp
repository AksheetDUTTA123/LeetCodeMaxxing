#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right){
            right = right & (right - 1); //this is the key, this operation removes the rightmost 1 bit from right, so we can find the common prefix of left and right by removing the rightmost 1 bits from right until it is less than or equal to left
        }
        return right;
    }
};
// @lc code=end

