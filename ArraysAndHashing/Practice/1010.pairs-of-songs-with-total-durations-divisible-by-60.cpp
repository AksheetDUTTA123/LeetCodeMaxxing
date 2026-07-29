#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int totalPairs = 0;
        unordered_map<int, int> seen;
        for(int i = 0; i < time.size(); i++){
            int currVal = time[i] % 60;
            if(seen.find((60 - currVal)% 60) != seen.end()){
                totalPairs += seen[(60 - currVal) % 60];
            }
            seen[currVal]++;
        }
        return totalPairs;
    }
};
// @lc code=end

