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
void backtracking(vector<int>& nums, int idx, vector<int>& curr){
    if(idx == nums.size()){
        res.push_back(curr);
        return;
    }

    //do not need this for loop but for sake of demonstrating i think it shows backtracking take it or leave it idea
    for(int i = 0; i < 2; i++){
        if(i == 0){ //leave it, we arent including this in the subset
            idx++;
            backtracking(nums, idx, curr);
            idx--;
        }
        else{
            curr.push_back(nums[idx]);
            idx++;
            backtracking(nums, idx, curr);
            curr.pop_back();
            idx--;
        }
    }
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr = {};
        int idx = 0;
        backtracking(nums, idx, curr);
        return res;
    }
};
// @lc code=end

