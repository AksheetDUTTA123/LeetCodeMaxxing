#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2126 lang=cpp
 *
 * [2126] Destroying Asteroids
 */

// @lc code=start
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long totalMax = mass;
        for(int i= 0; i< asteroids.size(); i++){
            if(asteroids[i] > totalMax){
                return false;
            }
            else{
                totalMax += asteroids[i];
            }
        }
        return true;
    }
};
// @lc code=end

