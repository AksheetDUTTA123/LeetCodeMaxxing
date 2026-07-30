#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int range = maxVal - minVal + 1;
        vector<int> counts(range, 0);
        for(int num : nums){
            counts[num - minVal]++;
        }

        vector<int> res;

        for(int i = 0; i < counts.size(); i++){
            if(counts[i] > 0){
                while(counts[i] > 0){
                    res.push_back(minVal + i);
                    counts[i]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

