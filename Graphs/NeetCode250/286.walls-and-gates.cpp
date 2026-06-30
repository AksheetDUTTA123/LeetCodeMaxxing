#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=286 lang=cpp
 *
 * [286] Walls and Gates
 */

// @lc code=start
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;

        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({i, j}); //in this question, just find all of the gates and push them into the queue, 
                    //then we will do a BFS from all of the gates at the same time, and update the distance to the nearest gate for each room
                }
            }
        }
    int dRow[4] = {-1, 1, 0, 0};
   int dCol[4] = {0, 0, -1, 1};
    while(!q.empty()){
       auto top = q.front();
       q.pop();
       for(int idx = 0; idx < 4; idx++){
        int currRow = top.first + dRow[idx];
        int currCol = top.second + dCol[idx];

        if(currRow >= 0 && currRow < rooms.size() && currCol>= 0 && currCol < rooms[0].size() && rooms[currRow][currCol] == 2147483647){
            //the key point is that if rooms[currRow][currCol] == 2147483647, then we know that the gate we popped off the queue is the closest gate to that room, 
            //because we are doing a BFS, so we are exploring all of the rooms that are 1 step away from the gate first, then all of the rooms that are 2 steps away from the gate, and so on. 
            //So if we find a room that is 2147483647, then we know that the gate we popped off the queue is the closest gate to that room, because we have already explored all of the rooms that are closer to the gate.
            rooms[currRow][currCol] = rooms[top.first][top.second] + 1; //distance will be the location you came from + 1
            q.push({currRow, currCol}); //need to now push the current location and continue BFS
        }
       }

    }
    }
};
// @lc code=end

