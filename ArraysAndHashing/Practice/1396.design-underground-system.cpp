#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
private:
unordered_map<int, pair<string, int>> checkInMap;
unordered_map<string, pair<int, int>> averageTimes;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string currDest = checkInMap[id].first + "->" + stationName;
        averageTimes[currDest].first += t - checkInMap[id].second;
        averageTimes[currDest].second += 1;

    }
    
    double getAverageTime(string startStation, string endStation) {
        string currPath = startStation + "->" + endStation;
        return  (double) averageTimes[currPath].first / averageTimes[currPath].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

