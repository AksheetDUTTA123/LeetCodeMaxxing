#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtracking(answer, "", 0, 0, n);
        return answer;
    }

private:
    void backtracking(vector<string>& answer, string current, int open, int close, int n){
        if(current.size() == 2*n){
            answer.push_back(current);
            return;
        }
        if(open < n){
            backtracking(answer, current + "(", open + 1, close, n);
        }
        if(close < open){
            backtracking(answer, current + ")", open, close + 1, n);
        }
    }
};
// @lc code=end

