#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2107 lang=cpp
 *
 * [2107] Number of Unique Flavors After Sharing K Candies
 */

// @lc code=start
class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        //sliding window, use  a map to check what I will have after giving k candies away
        unordered_map<int, int> totalSet;

        for(int i = 0; i < candies.size(); i++) totalSet[candies[i]]++;
        if(k == 0) return totalSet.size();

        for(int i = 0; i < k; i++){
            totalSet[candies[i]]--;
            if(totalSet[candies[i]] == 0) totalSet.erase(candies[i]);
        }

        int maxUniqueFlav = totalSet.size();

    for(int i = k; i < candies.size(); i++){
        totalSet[candies[i - k]]++;
        if(totalSet[candies[i - k]] == 0) totalSet.erase(candies[i - k]);

        totalSet[candies[i]]--;
        if(totalSet[candies[i]] == 0) totalSet.erase(candies[i]);
        maxUniqueFlav = std::max(maxUniqueFlav, (int) totalSet.size());
    }



        return  maxUniqueFlav;
    }
};
// @lc code=end

