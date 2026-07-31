#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3894 lang=cpp
 *
 * [3894] Traffic Signal Color
 */

// @lc code=start
class Solution {
public:
    string trafficSignal(int timer) {
        if(timer == 0) return "Green";
        else if (timer == 30) return "Orange";
        else if(timer > 30 && timer <= 90) return "Red";
        else return "Invalid";
    }
};
// @lc code=end

