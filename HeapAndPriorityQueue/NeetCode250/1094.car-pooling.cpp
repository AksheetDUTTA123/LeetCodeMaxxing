#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
// class Solution {
//this solution is the heap one, this is considered more space efficient 
//if unbounded distances
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         int currentNum = 0;
//         int currIdx = 0;
//         auto comparator = [](const pair<int, int>& p1, const pair<int, int>& p2){
//            return  p1.second > p2.second; //sort by stop time, earliest stop time comes first, this way we can easily 
//             remove passengers from the current number of passengers when we reach their stop time, because we can just check the top of the heap to see if the stop time of 
//the passengers at the top of the heap is less than or equal to the current start time of the next trip, if it is, then we can remove those passengers from the current number of passengers and 
//pop them from the heap, this way we can efficiently manage the number of passengers in the car at any given time, and we can easily check if we exceed the capacity of the car at any point in time
//         };
//         std::sort(trips.begin(), trips.end(), [](const vector<int> left, const vector<int> right){
//                 return left[1] < right[1]; //sort by start time, earliest start time comes first, this way we can easily add passengers
// to the current number of passengers when we reach their start time, because we can just iterate through the sorted trips array and add passengers to the current number of passengers when we reach their start time, 
//this will allow us to efficiently manage the number of passengers in the car at any given time, and we can easily check if we exceed the capacity of the car at any point in time
//         });
//         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq;

//         while(currIdx < trips.size()){
//             int numPassengers = trips[currIdx][0];
//             int startTime = trips[currIdx][1];
//             int stopTime = trips[currIdx][2];

//             while(!pq.empty() && pq.top().second <= startTime){ //this occurs when trips have stop times that are less than or equal to the start time of the next trip, this means that we have reached the stop time of some passengers,
// so we need to remove those passengers from the current number of passengers and pop them from the heap,
//                 currentNum -= pq.top().first;
//                 pq.pop();
//             }

//             currentNum += numPassengers; //after unloading passengers, we can add the passengers from the current trip to the current number of passengers, and then 
//we can check if we exceed the capacity of the car, if we do, then we can return false, because it is not possible to carpool all the trips without exceeding the capacity of the car
//             if(currentNum > capacity) return false;

//             pq.push({numPassengers, stopTime});
//             currIdx++; //move to the next trip
//         }



//         return true;
//     }
// };

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    //since location is bounded from 0 to 1000, you can use a prefix sum array here
    int locations[1001] = {0};

    int currCustomers = 0;
    for(auto trip : trips){
        int numPassengers = trip[0];
        int startLoc = trip[1];
        int endLoc = trip[2];

        locations[startLoc] += numPassengers; //addPassengers
        locations[endLoc] -= numPassengers; //removePassengers
    }
    for(int i = 0; i < 1001; i++){
        currCustomers += locations[i];
        if(currCustomers > capacity) return false;
    }
    return true;
    }
};


// @lc code=end

