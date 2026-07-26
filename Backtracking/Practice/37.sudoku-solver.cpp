#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
private: //backtracking has to be bool because thats how we know if the numbers on the grid work, if it doesnt, we have to backtrack until we can reorder
    bool backtracking(vector<vector<char>>& board, int i, int j, std::vector<std::unordered_set<char>>& rowContent, std::vector<std::unordered_set<char>>& colContent, std::vector<std::unordered_set<char>>& squareContent){
        if(i == 9) return true;

        if(j == 9) return backtracking(board, i + 1, 0, rowContent, colContent, squareContent);

        if(board[i][j] != '.') return backtracking(board, i, j+1, rowContent, colContent, squareContent);

        for(char ch = '1'; ch <= '9'; ch++){
            int boxIdx = (i/3) * 3 + (j/3);

            //check if valid first
            if(!rowContent[i].count(ch) && 
               !colContent[j].count(ch) &&
               !squareContent[boxIdx].count(ch)){
                rowContent[i].insert(ch);
                colContent[j].insert(ch);
                squareContent[boxIdx].insert(ch);
                board[i][j] = ch;

                if(backtracking(board, i, j + 1, rowContent, colContent, squareContent)) return true; //if true, we found the correct board, return true

                //if we return false, we will now backtrack, try a different digit
                board[i][j] = '.';
                rowContent[i].erase(ch);
                colContent[j].erase(ch);
                squareContent[boxIdx].erase(ch);
               }
        }
        return false; //no digit works, we have to backtrack to the previous call and recheck
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
    std::vector<std::unordered_set<char>> rowContent(board.size());
    std::vector<std::unordered_set<char>> colContent(board[0].size());
    std::vector<std::unordered_set<char>> squareContent(9);


    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] != '.'){
                rowContent[i].insert(board[i][j]);
                colContent[j].insert(board[i][j]);
                squareContent[(i/3) * 3 + (j/3)].insert(board[i][j]);
            }
        }
    }
    backtracking(board, 0, 0, rowContent, colContent, squareContent);
    }
};
// @lc code=end

