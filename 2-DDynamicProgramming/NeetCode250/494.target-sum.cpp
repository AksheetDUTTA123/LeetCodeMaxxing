#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int num : nums) totalSum += num;
        if(totalSum < abs(target)) return 0; //if the total sum of the array is less than the absolute value of the target, it is impossible to reach the target by adding or subtracting the numbers in the array, so we return 0
        if (((totalSum - target) % 2) != 0) return 0; //if the difference between the total sum and the target is odd, it is impossible to reach the target by adding or subtracting the numbers in the array, so we return 0
        int numNeg = (totalSum - target) / 2; //numNeg is the sum of the numbers that we need to subtract from the total sum to reach the target, we can think of this as a subset sum problem, where we want to find the number of ways to choose a subset of the numbers in the array that add up to numNeg
        //we divide by 2 because we are only interested in the numbers that we need to subtract, and the numbers that we need to add will automatically be the complement of the numbers that we need to subtract

        vector<int> dp(numNeg + 1, 0); //we make a 1D memo table to store the number of ways to reach each sum from 0 to numNeg, we only need to keep track of the current state, because we are only interested in the number of ways to reach numNeg
        dp[0] = 1;
        for(int num : nums){ //for each number in the array, we iterate backwards through the dp array to avoid using the same number multiple times, we want to see if we can make a sum of i by either taking the current number or not taking it
            for(int i = numNeg; i >= num; i--){
                dp[i] += dp[i - num];
            }
        }
        return dp[numNeg];
    }
};
// @lc code=end

