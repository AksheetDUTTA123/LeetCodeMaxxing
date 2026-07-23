#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // vector<bool> allRooms(rooms.size(), false);
        // allRooms[0] = true;
        // for(int i = 0; i < rooms.size(); i++){
        //     for(int j = 0; j < rooms[i].size(); j++){
        //         if(allRooms[i] == false) return false;
        //         allRooms[j] = true;
        //     }
        // }
        // bool res = true;
        // for(int i = 0; i < allRooms.size(); i++){
        //     if (allRooms[i] == false) res = false;
        // }
        // return res;
        //this above sol doesnt work, this is a graph traversla prob
        //need to do bfs with a queue

        vector<bool> allRooms(rooms.size(), false);
        queue<int> q;

        q.push(0);
        allRooms[0] = true;
        int visitedCt = 1;

        while (!q.empty()){
            auto front = q.front();
            q.pop();

            for(int key : rooms[front]){
                if(!allRooms[key]){
                allRooms[key] = true;
                visitedCt++;
                q.push(key);
                }
            }
        }
        return visitedCt == rooms.size();
    }
};
// @lc code=end

