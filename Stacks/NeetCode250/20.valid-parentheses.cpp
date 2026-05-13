#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
            char top = stk.top();
            stk.pop();
            if(
                (s[i] == ')' && top != '(')|| 
                (s[i] == ']' && top != '[') ||
                (s[i] == '}' && top != '{')
            ){
                return false;
            }
        }
        }
            return stk.empty();
    }
};
// @lc code=end

