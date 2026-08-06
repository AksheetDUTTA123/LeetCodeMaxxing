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
        columnNumber--;
        char currChar = ((columnNumber) % 26) + 'A';
        columnNumber /= 26;
        res += currChar;   
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

