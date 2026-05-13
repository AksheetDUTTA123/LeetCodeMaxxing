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
        std::stack<int> stk;
        int total = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int holder1 = stk.top();
                stk.pop();
                int holder2 = stk.top();
                int sum = holder1 + holder2;
                stk.push(holder1);
                stk.push(sum);
            }
            else if(operations[i] == "D"){
                stk.push(2 * stk.top());
            }
            else if(operations[i] == "C"){
                stk.pop();
            }
            else{
                stk.push(stoi(operations[i]));
            }
        }
        while(stk.size() > 0){
            total += stk.top();
            stk.pop();
        }
        return total;
    }
};
// @lc code=end

