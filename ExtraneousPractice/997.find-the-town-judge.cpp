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
        if (n == 1) return 1;
        vector<int> degree(n+1, 0);
        for(auto trusts : trust){
            degree[trusts[0]]--; //a trusts someone, negative
            degree[trusts[1]]++; //b is trusted by someone, positive
        }

        for(int i = 0; i < degree.size(); i++){
            if(degree[i] == n - 1) return i;
        }
        return -1;
    }
};
// @lc code=end

