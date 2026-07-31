#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3898 lang=cpp
 *
 * [3898] Find the Degree of Each Vertex
 */

// @lc code=start
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> adj(matrix.size());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                adj[j] += matrix[i][j]; //j is the point
            }
        }
        return adj;
    }
};
// @lc code=end

