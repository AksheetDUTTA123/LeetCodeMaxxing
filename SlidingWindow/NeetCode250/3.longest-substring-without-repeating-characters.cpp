#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int longest = 0;
        int leftW = 0;
        //int currLongest= 0;
        for(int i = 0; i < s.size(); i++){
            if(seen.find(s[i]) != seen.end() && seen[s[i]] >= leftW){ //alr seen that element before, seen after leftWindow marker
                longest = max(longest, i - leftW); //update longest before moving leftW, because current longest is from leftW to i, so length is i - leftW
                leftW = seen[s[i]] + 1; //move leftW to the right of the last seen index of the current character, start a new substring that doesnt include repeated char
                //clean optimization instead of having to iterate until you find the repeat
            }
           seen[s[i]] = i; //update the last seen index of the current character
        }
        return max(longest, (int)s.size() - leftW); //after loop, check if the longest substring is from leftW to the end of the string, if so, update longest accordingly
        //This is necessary because if the longest substring is at the end of the string, it would not have been update in the loop since the loop only updates longest when a repeat is found, 
        //and if the longest substring is at the end, there would be no repeat to trigger the update.

    }
};
// @lc code=end

