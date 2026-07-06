#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26, 0);
        vector<int> res;

        for(int i = 0; i < s.length(); i++){
            lastIdx[s[i] - 'a'] = i; //store the last index of each character in the string, 
            //this is important because we want to know when we can partition the string, we can only partition when we have seen all the characters in the current partition
        }

        int start = 0;
        int end = 0; //track start and end of current window, checking for the last index of each character in the current window,
        // if we have seen all the characters in the current window, we can partition the string

        for(int i = 0; i < s.length(); i++){
            end = max(end, lastIdx[s[i] - 'a']); //this is the key, we are updating the end of the current window 
            //to be the last index of the current character, this is because we want to make sure we have seen all the characters in the current window before we can partition the string


            if(i == end){ //if i is equal to end, we have seen all the characters in the current window, 
            //we can partition the string
                res.push_back(end - start + 1);
                start = end + 1; //update the start of the next window to be the next character after the current window
            }
        }
    return res;
    }
};
// @lc code=end

