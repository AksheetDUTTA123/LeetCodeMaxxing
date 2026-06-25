#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ')'){
                stk.push({s[i], i});
            }
            else if(s[i] == '('){
               if(!stk.empty()) {
                auto pair = stk.top();
                if(pair.first == ')'){
                    stk.pop();
                }
               }
               else{
                s[i] = '*';
               }
            }
            else{
                continue;
            }
        }
        while (!stk.empty()){
            auto top = stk.top();
            stk.pop();
            s[top.second] = '*';
        }
        string res = "";
        for(char c : s){
            if (c != '*') res += c;
                    }
                    return res;
    }
};
// @lc code=end

