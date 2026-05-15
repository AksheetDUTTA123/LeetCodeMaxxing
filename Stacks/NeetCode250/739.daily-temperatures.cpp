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
        vector<int> answer(temperatures.size(), 0); //store the result vector
        stack<int> days; //stack to keep track of the indices of the days
        for(int i = 0; i < temperatures.size(); i++){
            while(!days.empty() && temperatures[i] > temperatures[days.top()]){ //while the current temp is greater than the temp of the day at the top of the stack, a warmer day has been found
            //the reason we have a while loop is because there may be multiple days in the stack that are colder than the current day, so pop all of those off and then update the answer for all of those days
               int prevIndex = days.top(); //index of previous day with a colder temp
               days.pop(); //pop it off the stack
               answer[prevIndex] = i - prevIndex; //the number of days until a warmer day is the difference between the current index and the previous index

        }
        days.push(i); //push current day into the stack, use stack to check if a warmer day for that specific day will come
    }
    return answer;
    }

};
// @lc code=end

