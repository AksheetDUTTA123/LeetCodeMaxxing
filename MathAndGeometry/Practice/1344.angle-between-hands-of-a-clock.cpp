#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
 */

// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = 0;
        double minuteAngle = 6 * minutes;
        double hourAngle = 30 * (hour % 12) + 0.5 * minutes;
        return  min(fabs(minuteAngle - hourAngle), 360 - fabs(minuteAngle - hourAngle));
    }
};
// @lc code=end

