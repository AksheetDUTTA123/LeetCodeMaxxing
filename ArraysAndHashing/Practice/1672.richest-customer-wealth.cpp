#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(int i = 0; i < accounts.size(); i++){
            int currWealth = 0;
            for(int j = 0; j < accounts[i].size(); j++){
                currWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, currWealth);
        }
        return maxWealth;
    }
};
// @lc code=end

