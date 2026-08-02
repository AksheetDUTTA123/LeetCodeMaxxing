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

    void backtracking(vector<int>& nums, unordered_map<int, int>& visited, vector<int>& curr){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }

        for(auto num : visited){
            if(visited[num.first] == 0) continue;
            visited[num.first]--;
            curr.push_back(num.first);
            backtracking(nums, visited, curr);
            curr.pop_back();
            visited[num.first]++;
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> visited;
        for(int num : nums) visited[num]++;
        vector<int> curr;
        backtracking(nums, visited, curr);
        return res;
    }
};
// @lc code=end

