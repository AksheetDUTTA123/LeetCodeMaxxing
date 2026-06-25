#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<unsigned int> dp(target + 1, 0); //need to store as unsigned int, because the number of combinations can be very large, and we don't want to overflow the int type.
       //bound is target + 1, because we want to store the amount of combinaitons you can get up until target
        dp[0] = 1; //base case, empty function

        for(int i = 1; i <= target; i++){
            for(int num : nums){
                if(i >= num) dp[i] += dp[i-num]; //when you pick a number i, you now have to look for all the number of combinatins that can be made with the remaining target, which is i - num. 
                //So we add the number of combinations that can be made with the remaining target to the current number of combinations for the current target.
                //these number of combinatiions is what is stored within the memo table.
            }
        }
        return dp[target];
    }
};
// @lc code=end

