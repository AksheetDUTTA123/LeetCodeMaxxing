#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

/*
[3,2,1,0,4]


[2, 100, 0, 3]

if (currElement + jumpDist >= max){
return true;}
else{
c}
*/
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MaxIdx = 0;
        if(nums.size() == 1) return true;
        for(int i = 0 ; i < nums.size(); i++){
            if(MaxIdx < i) return false;
            MaxIdx = max(MaxIdx, nums[i] + i);
        }
        return true;
    }
};
// @lc code=end

