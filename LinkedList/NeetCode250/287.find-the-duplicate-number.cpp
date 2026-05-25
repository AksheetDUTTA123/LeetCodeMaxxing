#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //not a linked list problem, almost a two pointer problem, remember Floyd cycle dection algo tho
        int slow = nums[0]; //start at the beginning
        int fast = nums[0]; //start at the beginning
        while(true){
            slow = nums[slow]; //slow moves one step at a time, so we just follow the value of the current index to the next index
            fast = nums[nums[fast]]; //fast moves two steps at a time, so we follow the value of the current index to the next index, and then follow that value to the next index again
            if(slow == fast){
                break; //if equal, we found a point in the cycle 
            }
        }
        fast = nums[0]; //move fast back to the beginning, now we will move both slow and fast one step at a time until they meet, that is the start of the cycle, which is the duplicate number
        while(slow != fast){
            slow = nums[slow]; //move slow up by one, slow is alr at a point in the cycle
            fast = nums[fast]; //fast is at the beginning, so we follow the value to move it up by one, if it is not the duplicate, it will eventually meet up with slow at the cycle at the start of the cycle
        }
        return slow; //this is the start of the cycle
    }
};
// @lc code=end

