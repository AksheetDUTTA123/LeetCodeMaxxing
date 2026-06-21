#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res; //use a set
public:
    void backtrack(vector<int>& nums, vector<int>& curr, unordered_set<int>& set){
        if(set.size() == nums.size()){
            res.push_back(curr);
            return;
        }


        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) != set.end()) continue;
            set.insert(nums[i]);
            curr.push_back(nums[i]);
            backtrack(nums, curr, set);
            curr.pop_back();
            set.erase(nums[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    unordered_set<int> inCheck;
    vector<int> curr;
    backtrack(nums, curr, inCheck);
    return res;
    }
};
// @lc code=end

