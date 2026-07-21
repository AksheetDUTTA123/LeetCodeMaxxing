**#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=252 lang=cpp
 *
 * [252] Meeting Rooms
 */

// @lc code=start
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty()) return true;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < end){
                return false;
            }
            else{
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return true;
    }
};
// @lc code=end

