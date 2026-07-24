#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() + 1, 0);
        for(int i = stoneValue.size() - 1; i >= 0; i--){ //index has to start -1 or else out of bounds
            int maxOneStone = INT_MIN;
            int maxTwoStone = INT_MIN;
            int maxThreeStone = INT_MIN;

            if(i <= stoneValue.size() - 1){
                maxOneStone = stoneValue[i] - dp[i+1];
            }
            if(i + 1<= stoneValue.size() - 1) {
                maxTwoStone = stoneValue[i] + stoneValue[i + 1] - dp[i+2];
            }
            if(i + 2 <= stoneValue.size() - 1) maxThreeStone = stoneValue[i] + stoneValue[i + 1] + stoneValue[i+2] - dp[i+3];

            dp[i] = max(maxOneStone, max(maxTwoStone, maxThreeStone));
        }

        if(dp[0] > 0) return "Alice";
        else if(dp[0] < 0) return "Bob";
        else return "Tie";
    }
};
// @lc code=end

