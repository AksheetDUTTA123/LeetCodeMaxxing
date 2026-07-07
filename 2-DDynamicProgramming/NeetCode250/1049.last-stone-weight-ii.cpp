#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for(int stone : stones) totalSum += stone;
        int target = totalSum / 2; //we want to find the closest sum to half of the total sum,
        // because we want to minimize the difference between the two piles of stones, which is equivalent to finding the closest sum to half of the total sum
        vector<bool> dp(target + 1, false); //1D dp array, we only need to keep track of the current state,
        // because we are only interested in the closest sum to half of the total sum
        dp[0] = true; //base case, we can always make a sum of 0 by not taking any stones

        for(int stone : stones){
            for(int j = target; j >= stone; j--){ //we iterate backwards to avoid using the same stone multiple times, 
            //we want to see if we can make a sum of j by either taking the current stone or not taking it
                if(dp[j - stone]) dp[j] = true;
            }
        }

        int closestSum = 0;
        for(int i = dp.size() - 1; i >= 0; i--){
            if(dp[i]) {
                closestSum = i;
                break;
            }
        }

        return totalSum - 2 * closestSum; //the minimum possible weight of the last stone is the total sum of the stones minus twice the closest sum we can make to half of the total sum, 
        //because we want to minimize the difference between the two piles of stones
    }
};
// @lc code=end

