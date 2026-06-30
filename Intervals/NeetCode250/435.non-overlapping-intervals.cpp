#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int overlapCts = 0;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < end){
                overlapCts++;
                end = min(end, intervals[i][1]); //have to be greedy, to minimize overlaps, keep the one that ends earlier
                //the one that goes on longer can overlap with something else so that is something to track
                continue;
            }
            end = intervals[i][1];
        }
        return overlapCts;
    }
};
// @lc code=end

