#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1851 lang=cpp
 *
 * [1851] Minimum Interval to Include Each Query
 */

// @lc code=start
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size(), -1);
        sort(intervals.begin(), intervals.end(), 
        [](const auto &a, const auto &b){return a[1] - a[0] < b[1] - b[0];}); //sort intervals by length, so that 
        //we can find the minimum interval that includes the query, shortest interval first, so that we can find the minimum interval that includes the query, shortest interval first
        set<pair<int, int>> s;
        for(int i = 0; i < queries.size(); i++){
            s.insert({queries[i], i}); //insert the queries into a set, so that we can find the minimum interval that includes the query, 
            //shortest interval first
        }

        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];
            int length = end - start + 1;

            auto it = s.lower_bound({start, 0}); //find the first query that is greater than or equal to the start of the interval, so that we can find the minimum interval that includes the query, shortest interval first
            //{start, 0} is used to find the first query that is greater than or equal to the start of the interval, so that we can find the minimum interval that includes the query, shortest interval first
            //0 is just a placeholder floor so the smallest start query is found, so that we can find the minimum interval that includes the query, shortest interval first
            while(it != s.end() && it->first <= end){ //while the query is less than or equal to the end of the interval, so that we can find the minimum interval that includes the query, shortest interval first
                res[it->second] = length;
                it = s.erase(it);
                //it->first is the query, it->second is the index of the query in the original queries vector, so that we can find the minimum interval that includes the query, 
                //shortest interval first
                //it moves to the next query in the set, so that we can find the minimum interval that includes the query, shortest interval first, dont need it++
            }
        }
        return res;
    }
};
// @lc code=end

