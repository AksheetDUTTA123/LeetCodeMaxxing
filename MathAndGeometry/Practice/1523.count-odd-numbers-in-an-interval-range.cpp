#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        int total = (high - low) / 2;
        if(low % 2 == 1 || high % 2 == 1) total++;
        return total;
    }
};
// @lc code=end

