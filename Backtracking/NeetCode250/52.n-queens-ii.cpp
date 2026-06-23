#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
// @lc code=start
class Solution {
private:
    int count;
    vector<bool> occupiedCols;
    vector<bool> occupiedPosDiag;
    vector<bool> occupiedNegDiag;

public:
    
    void backtracking(int row, int n){
        if(row == n) {
            count++;
            return;
        }


        for(int col = 0; col < n; col++){
            if(occupiedCols[col] || occupiedPosDiag[row + col] || occupiedNegDiag[row - col + n - 1]){
                continue;
            } //row - col -n + 1 is the negative index because 
            //The minimum possible value of row - col is 0 - (n - 1) = -(n - 1). If we shift the index by adding n - 1 to every calculation, 
            //the values will cleanly map from 0 to 2n - 2.

            occupiedCols[col] = true;
            occupiedPosDiag[row + col] = true;
            occupiedNegDiag[row - col+ n - 1] = true;
            backtracking(row + 1, n);
            occupiedCols[col] = false;
            occupiedPosDiag[row + col] = false;
            occupiedNegDiag[row - col+ n - 1] = false;

        }
    }
    int totalNQueens(int n) {
        count = 0;
        occupiedCols.resize(n, false);
        occupiedPosDiag.resize(2*n, false);
        occupiedNegDiag.resize(2*n, false);
        backtracking(0, n);
        return count;
    }
};
// @lc code=end

