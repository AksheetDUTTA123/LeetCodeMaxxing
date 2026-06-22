#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for(char c : text) freq[c- 'a']++;
        int num = min(freq['b' - 'a'], freq['a' - 'a']);
        num = min(num, (freq['l' - 'a'] / 2));
        num = min(num, (freq['o' - 'a'] / 2));
        num = min(num, (freq['n' - 'a']));
        return num;
    }
};
// @lc code=end

