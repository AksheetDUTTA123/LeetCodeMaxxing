#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=422 lang=cpp
 *
 * [422] Valid Word Square
 */

// @lc code=start
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        //we know the rows will read the same thing, we basically just have to check cols

        for(int i = 0; i < words.size(); i++){
           for(int j = 0; j < words[i].size(); j++){
            if(j >= words.size() || i >= words[j].size()) return false; //if the current column is out of bounds of the number of rows, or if the current row is out of bounds of the number of columns, then it is not a valid word square
            if(words[i][j] != words[j][i]) return false;
           }
    }
    return true;
    }
};
// @lc code=end

