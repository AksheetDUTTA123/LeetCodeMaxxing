#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
public:
    static bool customComparator(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customComparator);
        int intervalCt = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){

            if(intervals[i][0] >= start && end >= intervals[i][1]){
                continue;
            }

            intervalCt++;
            start = intervals[i][0];
            end = intervals[i][1];
        }
        intervalCt++;
        return intervalCt;
    }
};
// @lc code=end

