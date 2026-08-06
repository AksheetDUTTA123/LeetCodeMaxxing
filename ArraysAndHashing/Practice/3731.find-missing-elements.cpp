#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3731 lang=cpp
 *
 * [3731] Find Missing Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minElem = *min_element(nums.begin(), nums.end());
        int maxElem= *max_element(nums.begin(), nums.end());
        vector<int> fullVec;
        vector<int> res;
        for(int i = minElem; i <= maxElem; i++){
            fullVec.push_back(i);
        }
        unordered_set<int> contain;
        for(int i = 0; i < nums.size(); i++){
            contain.insert(nums[i]);
        }
        for(int i = 0; i < fullVec.size(); i++){
            if(contain.find(fullVec[i]) == contain.end()){
                res.push_back(fullVec[i]);
            }
        }
        return res;
    }
};
// @lc code=end

