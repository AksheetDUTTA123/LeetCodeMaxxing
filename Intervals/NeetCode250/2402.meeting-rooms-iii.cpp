#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        auto comparator = [](const pair<long long, int> p1, const pair<long long, int> p2){ //need a comparator here, because we want to sort the busy rooms by end time,
        // and if two rooms have the same end time, we want to sort by room number, so that we can get the room with the smallest number
            if(p1.first == p2.first){
                            return p1.second > p2.second;
            }
            return p1.first > p2.first;
        };
        
        priority_queue<int, vector<int>, std::greater<int>> freeRooms; //order freeRooms by room number, so that we can get the room with the smallest number
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(comparator)> busy_rooms; //get the room with the earliest end time, and if two rooms have the same end time, get the room with the smallest number
        vector<int> roomCt(n, 0);
        sort(meetings.begin(), meetings.end());
        int currClock = 0;
        for(int i = 0; i < n; i++) freeRooms.push(i);

        for(auto meeting : meetings){
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            //at current start time, clear out all meetigns thar ended before this

            while(!busy_rooms.empty() && busy_rooms.top().first <= start){ //if a busy room has ended before the current meeting starts, 
            //we can free it up and add it to the freeRooms heap
                freeRooms.push(busy_rooms.top().second);
                busy_rooms.pop();
            }

            //now, add room, first we consider if there is a freeRoom available

            if(!freeRooms.empty()){
                int room = freeRooms.top();
                freeRooms.pop();

                roomCt[room]++;
                busy_rooms.push({end, room}); //add meeitng end time and room number to the busy rooms queue, update the roomCt, and remove the room from the freeRooms queue
            }
            else{

                auto top = busy_rooms.top();
                busy_rooms.pop(); //pop from busy rooms and we will readd it with the new end time, which is the current end time plus the duration of the meeting, and we will update the roomCt for that room


                roomCt[top.second]++;
                busy_rooms.push({top.first + duration, top.second});
            }
        }
        int maxCt = -1;
        int roomNum = -1;
        for(int i = 0; i < roomCt.size(); i++) {
            
            if(roomCt[i] > maxCt){
                roomNum = i;
                maxCt = roomCt[i];
            }
            
            }
        return roomNum;


    }
};
// @lc code=end

