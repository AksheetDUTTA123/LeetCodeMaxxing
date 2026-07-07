#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3754 lang=cpp
 *
 * [3754] Concatenate Non-Zero Digits and Multiply by Sum I
 */

// @lc code=start
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string num = to_string(n);
        string currNum = "";
        long long sum = 0;
        for(int i = 0; i < num.length(); i++){
            if(num[i] != '0') {
                currNum += num[i];
                sum += (num[i] - '0');
            }
        }

        return std::stoll(currNum) * sum;
    }
};
// @lc code=end

