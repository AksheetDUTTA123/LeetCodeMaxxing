#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
//in this quesiton, we are going through every element in each row, know that in queens
//queens can travel vertically, horizontally, and diagonally.
//horizonally is handled already because we are backtracking by each row, so it is not possible to have two queens in the same row, 
\//so we just need to check for vertical and diagonal conflicts when we are trying to place a queen in a row, we can use a hashset to keep track of which columns are occupied by queens, 
//and we can also use two hashsets to keep track of which diagonals are occupied by queens, one for the positive slope diagonals and one for the negative slope diagonals, this way we can 
//efficiently check for conflicts when we are trying to place a queen in a row, and if there are no conflicts, then we can place the queen and continue to the next row, if there are conflicts, 
//then we can skip that column and try the next column in the same row
class Solution {
private:
    vector<vector<string>> res;
    unordered_set<int> occupiedCols;
    unordered_set<int> occupiedPosDiag;
    unordered_set<int> occupiedNegDiag;
public:
    void backtracking(int row, int n, vector<string>& board){
        if(row == n){ //went through the whole row. we have successfully placed queens in all rows, 
        //so we can add the current board configuration to the result vector, and return to backtrack and try other configurations
            res.push_back(board);
            return;
        }
        
       for(int i = 0; i < n; i++){ //this is checking each column in a row, if there is something in the same col, or in same positive or negative diagonal, keep going, do not add a Q
            if(occupiedCols.count(i) || occupiedPosDiag.count(row + i) || occupiedNegDiag.count(row - i)){
            continue;
        }

        board[row][i] = 'Q';
        occupiedCols.insert(i);
        occupiedPosDiag.insert(row + i);
        occupiedNegDiag.insert(row - i);
        backtracking(row + 1, n, board);
        board[row][i] = '.';
        occupiedCols.erase(i);
        occupiedPosDiag.erase(row + i);
        occupiedNegDiag.erase(row - i);
       }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n, string(n, '.'));
        backtracking(0, n, curr);
        return res;
    }
};
// @lc code=end

