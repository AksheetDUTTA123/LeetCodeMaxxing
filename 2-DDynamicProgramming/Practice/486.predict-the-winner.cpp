#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //base case, we will mark dp[i][i] = nums[i], picking only elem in subarray
        for(int i = 0; i < nums.size(); i++){
            dp[i][i] = nums[i]; 
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j <n; j++){ //j is right bound, i is left bound
                dp[i][j] = max(nums[j] - dp[i][j-1], nums[i] - dp[i+1][j]);

                //j is what user picks, i to j-1 is optimal from opp
                //i is what user picks, i +1 to j is optimal from opponet
                //we pick the max one that is optimal for curr user
            }
        }

        return dp[0][n-1] >= 0;
    }
};
// @lc code=end

