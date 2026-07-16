#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        //lets fill A first, if there is a tie, we would rather have the 
        //bigger cost of B come first

        //above strat doesnt work, maybe, lets sort by differences! more negative means must go to A
        //and more positive mean go to B(since B is cheaper than A)
        sort(costs.begin(), costs.end(), [](const auto& a, const auto& b){
            return (a[0] - a[1] < b[0] - b[1]);
        });
        int totalCost = 0;
        for(int i = 0; i < n; i++){
            totalCost += costs[i][0];
        }

        for(int i = n; i < costs.size(); i++){
            totalCost += costs[i][1];
        }

        return totalCost;
    }
};
// @lc code=end

