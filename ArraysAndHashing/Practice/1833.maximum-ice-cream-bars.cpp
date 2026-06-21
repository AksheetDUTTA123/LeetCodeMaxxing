#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // int ctr = 0;
        // std::sort(costs.begin(), costs.end());
        // for(int i = 0; i < costs.size(); i++){
        //     if (coins - costs[i] < 0){
        //         return ctr;
        //     }

        //     ctr++;
        //     coins -= costs[i];
        // }
        // return ctr;

        //bucket sort 
        int maxCost = 0;
        for(int i = 0; i < costs.size(); i++){
            maxCost = max(maxCost, costs[i]);
        }
        vector<int> buckets(maxCost + 1, 0);
        for(int c : costs){
            buckets[c]++;
        }
        int ctr = 0;
        for(int price = 1; price < buckets.size(); price++){
            while(buckets[price] > 0 && coins >= price){
            ctr++;
            coins -= price;
            buckets[price]--;
            }
        }
        return ctr;
    }
};
// @lc code=end

