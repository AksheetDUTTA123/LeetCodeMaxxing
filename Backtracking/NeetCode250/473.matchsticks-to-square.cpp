#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool backtracking(int index, vector<int>& sides, vector<int>& matchSticks, int target){
        if(index == matchSticks.size()) return (sides[0] == target && sides[1] == target && sides[2] == target &&  sides[3] == target);
        //if index is matchsticks.size, we have added all the matchsticks to the sides, so we just need to check if all sides are equal to the target, if they are, then we can return true, 
        //otherwise we can return false

        for(int i = 0; i < 4; i++){
            if(matchSticks[index] + sides[i] <= target){ //we dont need to subtract from target like combination sum, because we are just checking if the current side is
            // less than or equal to the target, if it is, then we can add the matchstick to that side and continue to the next matchstick,
                sides[i] += matchSticks[index];
                if (backtracking(index + 1, sides, matchSticks, target)) return true; //move up index by one, this is because we want to try to fit the next matchstick in the next recursive call, 
                //and if we have successfully fit all matchsticks in the sides and reached the end of the matchsticks array, then we can return true, otherwise we can continue to try to fit the next matchstick
                // in the current side or in the next side
                sides[i] -= matchSticks[index];

            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
      int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

      if(totalSum % 4 != 0) return false; //early check, if not divisible by 4, square not possible
    int target = totalSum / 4; 
    vector<int> sides(4, 0);
    sort(matchsticks.rbegin(), matchsticks.rend()); //need to sort, because we want to try to fit the longest matchsticks first, 
    //this will allow us to quickly determine if a matchstick is too long to fit in any of the sides, and if it is, we can skip it 
    //and move on to the next matchstick, this will allow us to efficiently find a solution if one exists, and if we try to fit the shorter matchsticks first, 
    //we may end up trying to fit a long matchstick later on that cannot fit in any of the sides, which will lead to unnecessary backtracking and a longer runtime
    return backtracking(0, sides, matchsticks, target);
    
    }
};
// @lc code=end

