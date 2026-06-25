#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        int index = 0;
        for (char c : s){
        if(!stk.empty()){
        if((stk.top() == tolower(c) ||
            stk.top() == toupper(c)) && (stk.top() != c)){
                stk.pop();
                continue;
            }
        }
            stk.push(c);
        }
        string result = "";
        while (!stk.empty()){
            char c = stk.top();
            stk.pop();
            result += c;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

