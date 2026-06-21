#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
private:
vector<string> res;
public:
    void backtrack(int n, int index, int open, int close, string str){
        if (str.length() == 2 * n && open == n && close == n){
            res.push_back(str);
            return;
        }

            if(open < n){ //another open
                backtrack(n, index + 1, open + 1, close,  str + "(");
            }

            if (close < open){ //close
                backtrack(n, index + 1, open, close + 1, str + ")");
            }

    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(n, 0, 0, 0, curr);
        return res;
    }
};
// @lc code=end

