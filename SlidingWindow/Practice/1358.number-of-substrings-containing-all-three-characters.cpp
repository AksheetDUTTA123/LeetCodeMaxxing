#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
private:
public:
    int numberOfSubstrings(string s) {

        unordered_map<char, int> windowCheck;
        int numSubstr = 0;
        int left = 0;

        for(int endIdx = 0; endIdx < s.length(); endIdx++){
            windowCheck[s[endIdx]]++;
            while(windowCheck['a'] >= 1 && windowCheck['b'] >= 1 && windowCheck['c'] >= 1){
            numSubstr += (s.length() - endIdx); //all strings that can be made with letters thart come after endIdx should just be added, and we move left and check
            windowCheck[s[left]]--;
            left++;
        }
        }
        return numSubstr;
    }
};
// @lc code=end

