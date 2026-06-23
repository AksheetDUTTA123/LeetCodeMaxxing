#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
private:
    vector<int> memo;
public:
    int climbStairs(int n) {
        if(n == 1) return 1; //base case, there is only one way to climb one step,
        // which is to take one step
        int dp[n + 1]; //initialize memo table
        dp[0] = 0; //base case
        dp[1] = 1; //base case, there is only one way to climb one step, which is to take one step
        dp[2] = 2; //base case, there are two ways to climb two steps, which is to take two steps at once, or to take one step twice
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i - 2]; //the number of ways to climb to the ith step is the sum of the number of ways to 
            //climb to the (i-1)th step and the number of ways to climb to the (i-2)th step,
        }
        return dp[n];
        

        //fibonacci method, this is also O(n) time but this is O(1) space
        /*
                if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
        */
    }
};
// @lc code=end

