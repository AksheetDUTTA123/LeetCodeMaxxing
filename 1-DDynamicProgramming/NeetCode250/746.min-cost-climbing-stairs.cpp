#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev0 = cost[0]; //this is the minCost to reach the 0th step, 
        //we can either take 1 step from the -1th step or 2 steps from the -2th step, but since we are starting at the 0th step,
        // we can only take 1 step from the -1th step, which is the cost of the 0th step
        int prev1 = cost[1]; //this is the minCost to reach the first step

        for(int i = 2; i < cost.size(); i++){
            int currMin = cost[i] + min(prev0, prev1); //the minCost to reach the ith step is the cost of the ith step plus the minCost to reach the (i-1)th step 
            //or the (i-2)th step
            prev0 = prev1; //shift up by 1 for both prev0 and prev1
            prev1 = currMin;
        }
        return min(prev0, prev1); //the minCost can be achieved by taking 2 steps from prev0 or 1 step from prev1
        

    }
};
// @lc code=end

