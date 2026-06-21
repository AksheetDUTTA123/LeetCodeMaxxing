#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
public:
    void backtracking(vector<int>& nums, vector<int>& curr, int index){
        if(index == nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i = 0; i < 2; i++){
            if(i == 0){ //exclude, the next index cannot be a duplicate 
                int next_index = index + 1; //need to make a new variable here so that for doing the i == 1 loop, we can still use the original index variable to include the duplicate number, 
                //because if we update the index variable in the i == 0 loop, then we won't be able to include the duplicate number in the i == 1 loop, because the index variable will have been updated to skip over the duplicate number, so we need to make a new variable here to keep track of the next index that we need to backtrack from in the i == 0 loop, and we can use 
                //the original index variable in the i == 1 loop to include the duplicate number
                while(next_index < nums.size() && nums[next_index] == nums[index]){
                    next_index++;
                }
            backtracking(nums, curr, next_index);
            }
            else{
                curr.push_back(nums[index]);
                backtracking(nums, curr, index + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //still need to sort the array to make sure that duplicates are adjacent to each other, 
        //this will allow us to easily skip over duplicate numbers in the backtracking process, because if we have duplicate numbers that are 
        //not adjacent to each other, then we won't be able to easily skip over them in the backtracking process, because we won't be able to easily identify which numbers are 
        //duplicates and which numbers are not duplicates, so we need to sort the array to make sure that duplicates are adjacent to each other, this will allow us to easily skip over duplicate 
        //numbers in the backtracking process
        vector<int> curr;
        backtracking(nums, curr, 0);
        return res;
    }
};
// @lc code=end

