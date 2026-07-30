#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3014 lang=cpp
 *
 * [3014] Minimum Number of Pushes to Type Word I
 */

// @lc code=start
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
       for(int i = 0; i < word.length(); i++){
        freq[word[i] - 'a']++;
       }
       sort(freq.rbegin(), freq.rend());
       int ctr = 0;
       int idx = 0;
       while(idx < 26 && freq[idx] > 0){
        ctr += freq[idx] * ((idx / 8) + 1);
        idx++;
       }
       return ctr;
    }
};
// @lc code=end

