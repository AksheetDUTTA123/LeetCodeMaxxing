#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber != 0){
            columnNumber--; //fix because columns are 1-indexed, this will fix it to become 0 indeced
            res += (columnNumber % 26) + 'A';
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

