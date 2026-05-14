#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> days;
        for(int i = 0; i < temperatures.size(); i++){
            while(!days.empty() && temperatures[i] > temperatures[days.top()]){
               int prevIndex = days.top();
               days.pop();
               answer[prevIndex] = i - prevIndex;

        }
        days.push(i);
    }
    return answer;
    }

};
// @lc code=end

