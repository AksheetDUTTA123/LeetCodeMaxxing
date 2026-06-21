#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& nums, int index, vector<int>& curr){
        if(index == nums.size()){
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < 2; i++){
            if(i == 0){ //exclude
            backtrack(nums, index + 1, curr);
            }

            if(i == 1){ 
            curr.push_back(nums[index]);
            backtrack(nums, index + 1, curr);
            std::erase(curr, nums[index]); //pop_back is better imo here
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, 0, curr);
        return res;
    }
};
// @lc code=end

