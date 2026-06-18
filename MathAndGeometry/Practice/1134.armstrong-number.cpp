#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1134 lang=cpp
 *
 * [1134] Armstrong Number
 */

// @lc code=start
class Solution {
public:
    bool isArmstrong(int n) {
        int nLength = to_string(n).length();
        int sum = 0;
        int currVal = n;
        for(int i = 0; i < nLength; i++){
            sum +=  pow((currVal % 10), nLength);
            currVal /= 10;
        }
        if (sum == n) return true;
        return false;
    }
};
// @lc code=end

