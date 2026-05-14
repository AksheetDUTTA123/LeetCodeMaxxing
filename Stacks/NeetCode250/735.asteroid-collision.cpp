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
        // Stack to keep track of surviving asteroids
        // The stack maintains order from left to right (bottom to top)
        stack<int> past;

        // Process each asteroid from left to right
        for(int i = 0; i < asteroids.size(); i++){
            
            // Case 1: Current asteroid is moving LEFT (negative)
            if(asteroids[i] < 0){
                
                // Subcase 1.1: Stack empty OR top asteroid also moving left
                // No collision possible since both move same direction
                if(past.empty() || past.top() < 0){
                    past.push(asteroids[i]);
                }
                
                // Subcase 1.2: Current left-moving asteroid is LARGER than top right-moving asteroid
                else if(abs(asteroids[i]) > past.top()){
                    // Keep destroying right-moving asteroids that are smaller
                    while(!past.empty() && past.top() > 0 && abs(asteroids[i]) > past.top()){
                        past.pop();
                    }
                    
                    // After destroying all smaller asteroids, check the new top
                    if(past.empty() || past.top() < 0){
                        // All right-moving asteroids destroyed, current survives
                        past.push(asteroids[i]);
                    }
                    else if(past.top() > 0 && abs(asteroids[i]) == past.top()){
                        // Equal size: both are destroyed (pop the right-moving one)
                        past.pop();
                    }
                    // If past.top() > 0 && abs(asteroids[i]) < past.top()
                    // Current asteroid is destroyed, do nothing
                }
                
                // Subcase 1.3: Current left-moving asteroid is SMALLER than top right-moving asteroid
                else if(abs(asteroids[i]) < past.top()){
                    // Current asteroid is destroyed, move to next asteroid
                    continue;
                }
                
                // Subcase 1.4: Current left-moving asteroid is EQUAL to top right-moving asteroid
                else{ // equal
                    if(!past.empty() && past.top() > 0 && abs(asteroids[i]) == past.top()){
                        // Both explode - just remove the top right-moving asteroid
                        past.pop();
                    }
                }
            }
            
            // Case 2: Current asteroid is moving RIGHT (positive)
            // No collision possible yet (future left-moving asteroids might collide)
            else{
                past.push(asteroids[i]);
            }
        }
        
        // Build result vector from stack (stack gives reverse order)
        vector<int> ans(past.size());
        int index = past.size() - 1;  // Start from the last index
        
        // Pop from stack and fill from end to beginning to maintain original order
        while(!past.empty()){
            ans[index--] = past.top();  // Place top asteroid at current index, then decrement
            past.pop();
        }
        
        return ans;
    }
};
// @lc code=end