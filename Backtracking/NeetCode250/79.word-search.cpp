#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool backtracking(vector<vector<char>>& board, int row, int col, string& word, int index){
        if(index == word.length()) return true; //if index at word length, we are done because we have successfully found the entire word in the board, so we can return true
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false; //if out of bounds, return false

        if(board[row][col] != word[index]) return false; //if the current cell in the board does not match the current character 
        //in the word that we are looking for, then we can return false, because there is no point in continuing to search for the rest of 
        //the word in the board if the current cell does not match the current character in the word, this will allow us to optimize our backtracking process by avoiding unnecessary backtracking calls when we encounter a 
        //cell in the board that does not match the current character in the word that we are looking for
        
        
        char currChar = board[row][col];
        board[row][col] = '#'; //mark current cell as visited, we can also use a separate visited array, but this is more space efficient,
        // we just need to make sure to unmark it after the backtracking calls,
        bool found = (
            backtracking(board, row + 1, col, word, index + 1) ||
            backtracking(board, row - 1, col, word, index + 1) ||
            backtracking(board, row , col + 1, word, index + 1) ||
            backtracking(board, row , col - 1, word, index + 1) 
        ); //check all 4 directions, if any of them return true, 
        //then we can return true for the backtracking function, 
        //because that means that we have found the rest of the word in the board, 
        //and we can return true for the backtracking function, otherwise we can return false for the backtracking function, because that means that we have not found the rest of the word in the board, 
        //and we can return false for the backtracking function

        board[row][col] = currChar; //revert back to original character, follows common backtracking pattern of making a change, then reverting it back after the recursive calls, this will
        // allow us to explore all possible paths in the board without permanently modifying the board,
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        string curr = "";

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){ //have to find the first character of the word in the board to start 
                //the backtracking process, this will allow us to only start the backtracking process from cells in the board 
                //that match the first character of the word, which will help to optimize the backtracking process by reducing the number of unnecessary backtracking 
                //calls that we need to make, because if we start the backtracking process from cells in the board that do not match the first character of the word, then we will end up making a lot of unnecessary backtracking calls that will 
                //not lead to a solution, so we need to only start the backtracking process from cells in the board that match the first character of the word
                                    if (backtracking(board, i, j, word, 0)){ //kick off backtracking here
                                        return true; 
                                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

