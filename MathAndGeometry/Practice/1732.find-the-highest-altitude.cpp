#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAlt = 0;
        int currAlt = 0;
        for(int i = 0; i < gain.size(); i++){
            currAlt += gain[i];
            highestAlt = max(currAlt, highestAlt);
        }
        return highestAlt;
    }
};
// @lc code=end

