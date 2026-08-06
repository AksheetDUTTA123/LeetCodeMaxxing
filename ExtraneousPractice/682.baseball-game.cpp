#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C"){
                stk.pop();
            }
            else if(operations[i] == "D"){
                stk.push(2 * stk.top());
            }
            else if(operations[i] == "+"){
                int firstElem = stk.top();
                stk.pop();
                int secondElem = stk.top();
                stk.push(firstElem);
                stk.push(firstElem + secondElem);
            }
            else{
                stk.push(stoi(operations[i]));
            }
        }
        int score = 0;
        while (!stk.empty()){
            score += stk.top();
            stk.pop();
        }
        return score;
    }
};
// @lc code=end

