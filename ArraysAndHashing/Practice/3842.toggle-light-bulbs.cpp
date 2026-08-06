#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3842 lang=cpp
 *
 * [3842] Toggle Light Bulbs
 */

// @lc code=start
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        sort(bulbs.begin(), bulbs.end());
        vector<int> res;
        for(int i = 0; i < bulbs.size(); i++){
            if (res.empty()) res.push_back(bulbs[i]);
            else if(res.back() == bulbs[i]) res.pop_back();
            else res.push_back(bulbs[i]);
        }
        return res;
    }
};
// @lc code=end

