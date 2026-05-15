#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car(position.size()); //first stores position, second stores speed
        stack<double> fleet; //arrival times of the fleet, order will go from earliest at the bottom and latest at top of the stack
    
        for(int i = 0; i < position.size(); i++){
            car[i]= {position[i],speed[i]};
        }
        sort(car.begin(), car.end()); //sort, position A car can only catch cars that start ahead of it
        for(int i = car.size() - 1; i >= 0; i--){ //start from back since this will guarantee the lowest arrival time, so stack goes from low to high(at the top)
            double arrivalTime = (target - car[i].first)/(double)car[i].second;
            if(fleet.empty()){
                fleet.push(arrivalTime);
            }
            else{
                if(arrivalTime <= fleet.top()){
                    continue; //joins the top of the fleet, slows down, so number of fleets stay the same
                }
                else{
                    fleet.push(arrivalTime); //if arrival time is more than top of the stack
                    //then wont reach previous fleet, will create a new fleet
                }
            }
        }
        return fleet.size();
        //in theory, a stack is not needed, just store the latest arrivalTime instead, as that is what the top of the stack stores anyways
    }
};
// @lc code=end

