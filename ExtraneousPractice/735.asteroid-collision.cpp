#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int i = 0; i < asteroids.size(); i++){
            bool destroyed = false;
            if(stk.empty()) stk.push(asteroids[i]);
            else{
                if(stk.top() > 0 && asteroids[i] > 0) stk.push(asteroids[i]);
                else if(stk.top() < 0 && asteroids[i] > 0) stk.push(asteroids[i]);
                else{
                    while(!stk.empty() && stk.top() > 0 && asteroids[i] < 0){
                        if(abs(stk.top()) > abs(asteroids[i])){
                            destroyed = true;
                            break;
                        }
                        else if(abs(stk.top()) < abs(asteroids[i])){
                            stk.pop();
                        }
                        else{
                            stk.pop();
                            destroyed = true;
                            break;
                        }
                    }
                    if(!destroyed) stk.push(asteroids[i]);
                }
            }
        }
            vector<int> res;
            while(!stk.empty()){
                res.push_back(stk.top());
                stk.pop();
            }
            reverse(res.begin(), res.end());
            return res;
    }
};
// @lc code=end

