#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        int hammingWeight = 0;
        while (n > 0){
            n = n & (n-1);
            hammingWeight++;
        }
        return hammingWeight;
    }
};
// @lc code=end

