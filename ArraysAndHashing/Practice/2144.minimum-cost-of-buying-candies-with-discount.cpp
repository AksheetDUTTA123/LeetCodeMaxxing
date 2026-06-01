#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2144 lang=cpp
 *
 * [2144] Minimum Cost of Buying Candies With Discount
 */

// @lc code=start
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int totalSum = 0;
        if(cost.size() <= 2){
            totalSum = std::accumulate(cost.begin(), cost.end(), 0);
            return totalSum;
        }
        else{
            std::sort(cost.begin(), cost.end(), std::greater<int>());
            for(int i = 0; i < cost.size(); i++){
                if(i % 3 != 2 ){
                    totalSum += cost[i];
                }
            }
            return totalSum;
        }
    }
};
// @lc code=end

