#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true; //the first player can always win if they play optimally,
        // because the number of piles is even, and the first player can always choose either all the even indexed piles or all the odd indexed piles, and one of those two options will always have a greater total than the other, so the first player can always guarantee a win by choosing the option with the greater total.
    }
};
// @lc code=end

