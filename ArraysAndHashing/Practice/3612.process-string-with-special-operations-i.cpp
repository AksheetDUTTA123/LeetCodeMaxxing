#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3612 lang=cpp
 *
 * [3612] Process String with Special Operations I
 */

// @lc code=start
class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char c : s){
            if(c == '*'){
                if (res == "") res = "";
                res = res.substr(0, res.length() - 1);
            }
            else if(c == '#'){
                res += res;
            }
            else if(c == '%'){
                std::reverse(res.begin(), res.end());
            }
            else{
                res += c;
            }
        }
        return res;
    }
};
// @lc code=end

