#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int currNum = 0;
        for(int i = 0; i < columnTitle.length() - 1; i++){
            int curr = (columnTitle[i] - 'A') + 1;
            currNum += (pow(26, columnTitle.length() - 1 - i)) * curr;
        }
        currNum += (columnTitle[columnTitle.length() - 1] - 'A') + 1;
        return currNum;
    }
};
// @lc code=end

