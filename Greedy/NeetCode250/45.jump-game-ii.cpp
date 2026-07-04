#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        //I did the DP sol, it is inefficient tho at O(n^2), greedy is O(n)
        // vector<int> dp(nums.size(), nums.size());

        // dp[0] = 0;

        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j <= std::min((int)nums.size() - 1, i + nums[i]); j++){
        //         dp[j] = min(dp[j], dp[i] + 1);
        //     }
        // }
        
        // return dp[nums.size() - 1];

        int result = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size() - 1){ 
            int furthest = 0;
            for(int i = left; i <= right; i++){
                furthest = max(furthest, nums[i] + i); //here, we are checking the furthest index we can reach from the current window of indices 
                //[left, right]. We iterate through all indices in this window and calculate the maximum index we can reach by adding the value at that index (nums[i]) to the index itself (i). 
                //This gives us the furthest point we can jump to from any of the indices in the current window.
            }
            result++;

            if(furthest >= nums.size() - 1) return result;
            left = right + 1; //we update the left pointer to be one more than the current right pointer, effectively moving our window to the next set of indices we can jump from.
            right = furthest;  //we update the right pointer to be the furthest index we can reach from the current window. This sets up our new window of indices for the next iteration of the while loop.
        }
        return result;
    }
};
// @lc code=end

