#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
public:
    pair<int , int> rowCol (int currPos, int n){
        int r = (currPos - 1) / n;
        int c = (currPos - 1) % n;
        int row = n - r- 1;
        int col = 0;
        if(r % 2 == 0){
            col = c; //we want to go left to right, so col = c
        }
        else{
            col = n - 1 - c; //we want to go right to left, so col = n - 1 - c
        }

        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> q; //we are storing {currPos, min Moves taken}
        int currRoll = 0;
        int currPos = 1;
        int target = board.size() * board[0].size();
        vector<bool> visited(target + 1, false);
        q.push({1, 0});
        visited[1] = true;
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            if(top.first == target) return top.second;

            for(int i = top.first + 1; i <= min(top.first + 6, target); i++){
                auto [row, col] = rowCol(i, board.size());
                int dest = board[row][col];
                if(dest != -1){
                    if(!visited[dest]){
                        visited[dest] = true; //mark the new position as visited
                        q.push({dest, top.second + 1});
                    }
                }
                else{
                    if(!visited[i]){
                        visited[i] = true; //mark the new position as visited
                        q.push({i, top.second + 1});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

