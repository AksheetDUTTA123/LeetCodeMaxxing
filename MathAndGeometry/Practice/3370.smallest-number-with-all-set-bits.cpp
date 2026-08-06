#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3370 lang=cpp
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
class Solution {
public:
    int smallestNumber(int n) {
        for(int i = 0; i <= 10; i++){
            if (pow(2, i) - 1 >= n) return pow(2, i) - 1;
        }
        return -1;
    }
};
// @lc code=end

