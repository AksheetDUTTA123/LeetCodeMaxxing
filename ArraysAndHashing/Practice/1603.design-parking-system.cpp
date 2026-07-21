#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
private:
int bigHold = 0;
int mediumHold = 0;
int smallHold = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        bigHold = big;
        mediumHold = medium;
        smallHold = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(bigHold == 0) return false;
            bigHold--;
            return true;
        }
        else if (carType == 2){
            if(mediumHold == 0) return false;
            mediumHold--;
            return true;
        }
        else{
            if(smallHold == 0) return false;
            smallHold--;
            return true;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

