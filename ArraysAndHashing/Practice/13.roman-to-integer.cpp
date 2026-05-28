#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int idx = s.size() - 1;
        int result = 0;
unordered_map<string, int> romanMap = {
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
    {"C", 100},  {"XC", 90},  {"L", 50},  {"XL", 40},
    {"X", 10},   {"IX", 9},   {"V", 5},   {"IV", 4},
    {"I", 1}
};
        while (idx>= 0){
            if(idx > 0){
            if(romanMap.find(s.substr(idx - 1, 2)) != romanMap.end()){
                        result += romanMap[s.substr(idx - 1, 2)];
                        idx -= 2;
                        continue;
            }
            }

            result += romanMap[string(1, s[idx])];
            idx -= 1;
        }
        return result;
    }
};
// @lc code=end

