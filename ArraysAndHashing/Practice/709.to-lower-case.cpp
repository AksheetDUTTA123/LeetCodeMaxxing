#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        string result = "";
        for(int i = 0; i < s.length(); i++){
            result += tolower(s[i]);
        }
        return result;
    }
};
// @lc code=end

