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

//use counting sort for this question, easiest way to conceptualize for O(n log n)
    vector<int> sortArray(vector<int>& nums) {
        // unordered_map<int, int> storedVals; //
        // for(int i = 0; i < nums.size(); i++){
        //     storedVals[nums[i]]++;
        // }
            int minElement = *min_element(nums.begin(), nums.end());
            int maxElement = *max_element(nums.begin(), nums.end());
            int range = maxElement - minElement + 1;
            vector<int> count(range, 0);
            for(int num : nums){
                count[num-minElement]++;
            }
            int j = 0; //use as index
            for(int i = 0; i < range; i++){
                while(count[i]-- > 0){
                    nums[j++]=i + minElement;
                }
            }
        return nums;
    }
};
// @lc code=end

