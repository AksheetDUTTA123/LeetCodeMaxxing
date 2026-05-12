#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowSet[9];
        unordered_set<char> colSet[9];
        unordered_set<char> boxes[3][3];
    for(int i= 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == '.'){
                continue;
            }
            else if(rowSet[i].find(board[i][j]) == rowSet[i].end() && colSet[j].find(board[i][j]) == colSet[j].end() && boxes[i/3][j/3].find(board[i][j]) == boxes[i/3][j/3].end()){
                rowSet[i].insert(board[i][j]);
                colSet[j].insert(board[i][j]);
                boxes[i/3][j/3].insert(board[i][j]);

            }
            else{
                return false;
            }
        }
    }

    return true;

    }
};
// @lc code=end

