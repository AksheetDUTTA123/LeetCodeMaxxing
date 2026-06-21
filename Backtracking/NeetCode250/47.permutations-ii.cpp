#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
public:
    void backtracking(vector<int>& nums, vector<int>& curr, unordered_map<int, int>& visited){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        for(auto num: visited){ //have to go through the visited map instead of the nums array,
        // because we need to keep track of how many times we have used each number in the nums array, 
        //and if we go through the nums array, we won't be able to keep track of how many times we have used each number,
        // because there may be duplicates in the nums array, so we need to go through the visited map, which will allow us to keep track of how many times we have used each number in the nums array,
        // and if we have used a number more times than it appears in the nums array, then we can skip that number in the backtracking process, this way we can avoid generating duplicate permutations

        //its like if we used i = 0 to nums.size, we still start new branches with duplicates, 
        //but if we use the visited map, then we can keep track of how many times we have used each number,
        // and if we have used a number more times than it appears in the nums array, then we can skip that number in the backtracking process,
        // this way we can avoid generating duplicate permutations
            if(visited[num.first] == 0){ continue;}
            visited[num.first]--;
            curr.push_back(num.first);
            backtracking(nums, curr, visited);
            curr.pop_back();
            visited[num.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      unordered_map<int, int> countMap;
      for(int num:nums) countMap[num]++;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtracking(nums, curr, countMap);
        return res;
    }
};
// @lc code=end

