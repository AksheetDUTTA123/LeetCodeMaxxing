#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustScore(n + 1, 0);
        
        for (const auto& relation : trust) {
            int citizen = relation[0];
            int candidate = relation[1];
            
            trustScore[citizen]--;   // Citizen trusts someone, reduce score
            trustScore[candidate]++; // Candidate gains trust, increase score
        }
        
        // The judge must have a net score of exactly n - 1
        for (int i = 1; i <= n; i++) {
            if (trustScore[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};
// @lc code=end

