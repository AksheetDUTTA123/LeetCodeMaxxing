#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0;
        int totCost = 0;
        for(int i = 0; i < gas.size(); i++){
            totGas += gas[i];
            totCost += cost[i];
        }
        if (totCost > totGas) return -1;

        int currentTank = 0;
        int currentSurplus = 0;
        int startIdx = 0;

        for(int i = 0; i < gas.size(); i++){
            int diff = gas[i] - cost[i];
            currentTank += diff;
            currentSurplus += diff;

            if(currentTank < 0){ //gas being 0 is ok, just cant be less, if less, move start to position after the one you are at right now
            // and reset tank to 0
                currentTank = 0;
                startIdx = i + 1;
            }

        }
        return startIdx;
    }
};
// @lc code=end

