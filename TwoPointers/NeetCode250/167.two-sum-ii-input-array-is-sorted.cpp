#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        vector<int> ans(2);
        while(numbers[index1] + numbers[index2] != target){
            if(numbers[index1] + numbers[index2] < target){
                index1++;
            }
            else{
                index2--;
            }
        }
        ans[0] = index1 + 1;
        ans[1] = index2 + 1;
        return ans;
    }
};
// @lc code=end

