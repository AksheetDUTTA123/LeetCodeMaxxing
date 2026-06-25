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
//         ==========================================================================
// DRY RUN TRACE: stoneValue = [1, 2, 3, 7] (n = 4)
// Initial State: dp = [0, 0, 0, 0, 0]  (dp[4] = 0 is the base case)
// ==========================================================================

// --------------------------------------------------------------------------
// STEP 1: i = 3 (Evaluating choices for the last stone [7])
// --------------------------------------------------------------------------
// * oneStone:   stoneValue[3] - dp[4] 
//               = 7 - 0 = 7
// * twoStone:   (Out of bounds condition '3 + 1 < 4' fails) 
//               = INT_MIN
// * threeStone: (Out of bounds condition '3 + 2 < 4' fails) 
//               = INT_MIN

// dp[3] = max(7, max(INT_MIN, INT_MIN)) = 7
// Current dp array status: [0, 0, 0, 7, 0]


// --------------------------------------------------------------------------
// STEP 2: i = 2 (Evaluating choices for stones [3, 7])
// --------------------------------------------------------------------------
// * oneStone:   stoneValue[2] - dp[3] 
//               = 3 - 7 = -4
// * twoStone:   (stoneValue[2] + stoneValue[3]) - dp[4] 
//               = (3 + 7) - 0 = 10
// * threeStone: (Out of bounds condition '2 + 2 < 4' fails) 
//               = INT_MIN

// dp[2] = max(-4, max(10, INT_MIN)) = 10
// Current dp array status: [0, 0, 10, 7, 0]


// --------------------------------------------------------------------------
// STEP 3: i = 1 (Evaluating choices for stones [2, 3, 7])
// --------------------------------------------------------------------------
// * oneStone:   stoneValue[1] - dp[2] 
//               = 2 - 10 = -8
// * twoStone:   (stoneValue[1] + stoneValue[2]) - dp[3] 
//               = (2 + 3) - 7 = -2
// * threeStone: (stoneValue[1] + stoneValue[2] + stoneValue[3]) - dp[4] 
//               = (2 + 3 + 7) - 0 = 12

// dp[1] = max(-8, max(-2, 12)) = 12
// Current dp array status: [0, 12, 10, 7, 0]


// --------------------------------------------------------------------------
// STEP 4: i = 0 (Alice's Opening Move! Evaluating full array [1, 2, 3, 7])
// --------------------------------------------------------------------------
// * oneStone:   stoneValue[0] - dp[1] 
//               = 1 - 12 = -11
// * twoStone:   (stoneValue[0] + stoneValue[1]) - dp[2] 
//               = (1 + 2) - 10 = -7
// * threeStone: (stoneValue[0] + stoneValue[1] + stoneValue[2]) - dp[3] 
//               = (1 + 2 + 3) - 7 = -1

// dp[0] = max(-11, max(-7, -1)) = -1
// Final dp array status: [-1, 12, 10, 7, 0]


// ==========================================================================
// FINAL EVALUATION
// ==========================================================================
// Check dp[0]:
// dp[0] is -1. Because -1 < 0, Alice has a net disadvantage.

// Output: "Bob"

        vector<int> dp(stoneValue.size() + 1, 0); //for this question, the trick is you have to start from the last stone and work your way down to the first stone, 
        //because the last stone is the base case, and you can only take 1, 2, or 3 stones at a time, so you have to start from the last stone and work your way down to the first stone.
        //we will still iterate through every stone and find the maximum score we can get from that stone, but we will use the dp array to store the maximum score we can get from that stone, 
        //and we will use that to calculate the maximum score we can get from the previous stones.
        //say we start from the end of stoneVal and work our way down to dp[0]
        for(int i = stoneValue.size() - 1; i >= 0; i--){
             int oneStone = INT_MIN; //our three cases, player takes either one, two or three stones
            int twoStone = INT_MIN;
            int threeStone =INT_MIN;
            if(i <= stoneValue.size() - 1){
                 oneStone = stoneValue[i] - dp[i + 1]; //dp[i + 1] is opponent so essentially, current player takes the stone and then the opponent takes the next stone, so we subtract the opponent's score from the current player's score
            }
            if(i + 1 <= stoneValue.size() - 1){
        twoStone = stoneValue[i] + stoneValue[i+1] - dp[i + 2]; //current player takes two stones, and dp[i + 2] is the opponent's score(this is the optimal score the opponent can have at this moment), 
        //so we subtract the opponent's score from the current player's score

            }
            if(i + 2 <= stoneValue.size() - 1){
            threeStone = stoneValue[i] + stoneValue[i + 1] + stoneValue[i+2] - dp[i+3];
            }
            dp[i] = max(oneStone, max(twoStone, threeStone));
        }
        if(dp[0] > 0){
            return "Alice";
        }
        else if(dp[0] < 0) return "Bob";
        else return "Tie";
    }
};
// @lc code=end

