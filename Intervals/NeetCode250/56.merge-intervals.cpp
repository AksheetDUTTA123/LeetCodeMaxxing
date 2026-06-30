#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start

/*

[1,4] [4, 7]
 
start = 1
end = 
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = max(intervals[i][1], end); //have to take the max ending, because an intevral can engulf another interval entirely, take later one
            }
            //if not overlapping
            else{
            res.push_back({start , end});
            start = intervals[i][0]; //keep the start and end tracked properly by moving it up
            end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};
// @lc code=end

