#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        if(bills[0]  == 10 || bills[0]  == 20) return false;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) five++;
            else if (bills[i] == 10){
                ten++;
                if(five > 0) five--;
                else return false;
            }
            else{
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(five > 2){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;


    }
};
// @lc code=end

