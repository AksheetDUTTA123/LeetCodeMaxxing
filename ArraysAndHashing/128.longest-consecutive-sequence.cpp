#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //I initially considered using bucket sort, but lets try hash map

        unordered_set<int> LCS(nums.begin(), nums.end()); //go thru the nums array, add to the set
        int longest = 0; //use this to track the longest sequence
        for (int num : LCS){ //go thru the set
        int currentNum = 0; //start the number we are at
        int currentStreak = 0; //start streak at 0
        if(LCS.find(num-1) == LCS.end()){ 
            currentNum = num; //mark the number at where the streak starts
            currentStreak = 1; //set streak to 1 since no number comes before, this marks beginning of streak
            //ensure previous # is not there, start subsequence
            while(LCS.find(currentNum + 1)!= LCS.end()){ //keep streak going when the next number is found in the set, and if it isnt, we know the streak ends, dont go in while loop
                currentStreak++; //increment streak
                currentNum++; //we move to the next number in the streak
            }
        } 
        longest = max(longest, currentStreak); //if currentStreak is longer than the previous longest, update the longest to currentStreak
        }
        return longest; //at the end, return the LCS length
    }
};
// @lc code=end

