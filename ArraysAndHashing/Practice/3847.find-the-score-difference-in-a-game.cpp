#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3847 lang=cpp
 *
 * [3847] Find the Score Difference in a Game
 */

// @lc code=start
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int Active = 0;
        int NonActive = 0;
        bool firstPlayerActive = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){
                int tmp = Active;
                Active = NonActive;
                NonActive = tmp;
                firstPlayerActive = !firstPlayerActive;
            }
            if((i + 1) % 6 == 0){
                int tmp = Active;
                Active = NonActive;
                NonActive = tmp;
                firstPlayerActive = !firstPlayerActive;
            }
            Active += nums[i];
        }
        if(firstPlayerActive) return Active - NonActive;
        else return NonActive - Active;

    }
};
// @lc code=end

