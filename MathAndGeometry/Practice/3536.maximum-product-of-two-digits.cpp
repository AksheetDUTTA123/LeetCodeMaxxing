#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3536 lang=cpp
 *
 * [3536] Maximum Product of Two Digits
 */

// @lc code=start
class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n != 0){
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(), digits.end());
        return digits[digits.size() - 1] * digits[digits.size() - 2];
    }
};
// @lc code=end

