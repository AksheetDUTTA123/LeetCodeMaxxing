#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& row : image){
            reverse(row.begin(), row.end());
            for(auto& digit : row){
                if(digit == 1) digit = 0;
                else digit = 1;
            }
        }
        return image;
    }
};
// @lc code=end

