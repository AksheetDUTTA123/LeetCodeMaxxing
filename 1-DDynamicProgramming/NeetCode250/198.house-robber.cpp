#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int prevMaxProfit = nums[0]; //max amount of profit we can make up to the previous house, 
        //this is the max profit we can make if we rob the previous house, we need to keep track of this because we 
        //cannot rob two adjacent houses, so if we rob the current house, we cannot rob the previous house, and we need to know the max profit we can make if we rob the previous house, 
        //so we can add that to the current house's value to get the max profit we can make if we rob the current house
        int TwoPrevMax = 0; //max profit from the house two down, this is needed because if we want to rob the current house, we take the max profit from two houses down

        for(int i = 1; i < nums.size(); i++){ //go down till the end of houses
            int robCurr = TwoPrevMax + nums[i]; //if robbing curr, have to take the max from two houses down and add the curr val
            int skipCurr = prevMaxProfit; //the previous house max is he same as this house max, because if we skip the current house,
            // then the max profit we can make is the same as the max profit we can make if we rob the previous house,
            // because we cannot rob two adjacent houses, so if we skip the current house, then we cannot rob the previous house,
            // and we need to know the max profit we can make if we rob the previous house, so we can add that to the current house's 
            //value to get the max profit we can make if we rob the current house
            int currMax = max(robCurr, skipCurr); //max amount of profit we can have at the house i

            //now have to move up by 1
            TwoPrevMax = prevMaxProfit; //two houses down becomes the previous house max, because we are moving up by one house, so the previous house max becomes the two houses down max
            prevMaxProfit = currMax; //the previous house max becomes the current house max, move up by one house
        }

    return prevMaxProfit; //return the max profit we can make if we rob the last house, 
    //because we have gone through all the houses and calculated the max profit we can make if we rob each house, 
    //and the last house's max profit is the max profit we can make if we rob the last house
    }
};
// @lc code=end

