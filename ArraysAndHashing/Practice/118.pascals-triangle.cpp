#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 1) {
            res.push_back({1});
            return res;
        }
        if(numRows == 2){
            res.push_back({1});
            res.push_back({1, 1});
            return res;
        }
        res.push_back({1});
        res.push_back({1, 1});
        for(int i = 3; i <= numRows; i++){
            vector<int> currRow;
            currRow.push_back(1);
            int left = 0;
            int right = 1;
            while(right < i- 1){
                currRow.push_back(res[i-2][left] + res[i-2][right]);
                left++;
                right++;
            }
        currRow.push_back(1);
        res.push_back(currRow);
        }
        return res;
    }
};
// @lc code=end

