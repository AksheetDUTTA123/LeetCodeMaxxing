#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 0) return 0;

        vector<int> suffixSum(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }


        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); //dp[i][m] = max stones player can get starting from index i with m as the current M value

        for(int i = n - 1; i >= 0; i--){ //start from the end of the piles and work backwards, because we want to know the maximum stones the current player can get starting from index i with m as the current M value
            for(int m = 1; m <= n ; m++){ //start from the maximum possible M value and work backwards, because we want to know the maximum stones the current player can get starting from index i with m as the current M value
                //if can sweep rest of board, take it all
                if(i + 2 * m >= n){
                    dp[i][m] = suffixSum[i]; 
                }
                else{
                  int maxStones = 0;
                    for(int x = 1; x <= 2 * m; x++) {
                        int currentChoice = suffixSum[i] - dp[i + x][max(m, x)]; //currentChoice is the maximum stones the current player can get starting from index i with m as the current M value,
                        //i + x is the index of the next player, and max(m, x) is the new M value for the next player
                        maxStones = max(maxStones, currentChoice);
                    }
                    dp[i][m] = maxStones;
                }
            }
        }

        return dp[0][1];
    }
};
// @lc code=end

