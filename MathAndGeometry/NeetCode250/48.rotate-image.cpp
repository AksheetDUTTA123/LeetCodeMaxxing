#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */


//ex 1:
()


// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       for(int i = 0; i < matrix.size() - 1; i++) {
        for(int j = i + 1; j< matrix[0].size(); j++){
            std::swap( matrix[i][j], matrix[j][i]);
        }
       }

        for(int i = 0; i < matrix.size(); i++){
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end

