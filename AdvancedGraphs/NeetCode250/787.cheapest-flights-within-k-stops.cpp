#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //good example of bellman ford, shortest path with limited stops

        vector<int> prices(n, INT_MAX);
        prices[src] = 0;


        for(int i = 0; i <= k; i++) {//k stops = k + 1 flights
            //keep track of distances, save a temp now and update later
            vector<int> temp = prices;
            for(auto flight : flights){
                int start = flight[0];
                int end = flight[1];
                int price = flight[2];

                if(prices[start] != INT_MAX && prices[start] + price < temp[end]){ //here, we have to check if start is reachable in the first place and if the new price is cheaper than the current price at end
                    temp[end] = prices[start] + price;
                }
            }
            prices = temp; //update the prices vector after each iteration, because we want to keep track of the minimum price to reach each city with at most k stops
        }

        if(prices[dst] == INT_MAX) return -1;

        return prices[dst];
    }
};
// @lc code=end

