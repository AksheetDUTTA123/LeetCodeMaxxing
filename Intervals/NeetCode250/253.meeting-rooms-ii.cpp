#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        pq.push(intervals[0][1]);

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= pq.top()) pq.pop(); //if the start time of the current interval is greater than or equal to the end time of the earliest ending meeting, we can reuse that room, so we pop it from the priority queue
            pq.push(intervals[i][1]); //always push, because this is akin to adding a new meeting room, because we have to account for the current meeting
        }
        return pq.size();
    }
};
// @lc code=end

