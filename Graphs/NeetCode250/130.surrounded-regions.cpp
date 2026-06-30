#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int dRow[4] = {1, -1, 0, 0};
        int dCol[4] = {0, 0, 1, -1};
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'E';
            }
        }
        for(int i = 0; i < board.size(); i++){
            if(board[i][board[0].size()-1] == 'O') {
                q.push({i, board[0].size() - 1});
                 board[i][board[0].size()-1] = 'E';
        }
        }
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = 'E';
            }
        }
        for(int i = 0; i < board[0].size(); i++){
            if(board[board.size() - 1][i] == 'O'){
                q.push({board.size() - 1, i});
                board[board.size() - 1][i] = 'E';
            } 
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(int idx = 0; idx < 4; idx++){
                int currRow = top.first + dRow[idx];
                int currCol = top.second + dCol[idx];

                while(currRow >= 0 && currRow < board.size() && currCol >= 0 && currCol < board[0].size() && board[currRow][currCol] == 'O'){
                    q.push({currRow, currCol});
                    board[currRow][currCol] = 'E';
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X'; 
            }
        }
        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'E') board[i][j] = 'O'; 
            }
        }
    }
};
// @lc code=end

