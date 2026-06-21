#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
private:
    int sum;
public:
    void backTrack(vector<int>& nums, int index, int currentXOR){
        if(index == nums.size()) {
         sum += currentXOR;
         return;   
        }

        for(int i = 0; i < 2; i++){
            //pretend like this is a tree, with 0 being include and 1 being exclude, we can do a backtracking approach to explore all possible subsets of the nums array, and for each subset, 
            //we can calculate the XOR total of that subset and add it to the sum variable, this will allow us to calculate the sum of all subset XOR totals by exploring all possible subsets of 
            //the nums array and calculating their XOR totals

            //say i == 0 is include
            if(i == 0){
                currentXOR = currentXOR ^ nums[index]; //include the current number in the XOR total, we can do this by XORing the currentXOR with the current number at the index, this will give us the new XOR total for the subset that includes the current number
                backTrack(nums, index + 1, currentXOR); //move on to the next index, this will allow us to explore the next level of the tree, which represents the next number in the nums array, and we can continue to explore all possible subsets of the nums array by recursively calling the backTrack function for each level of the tree
                currentXOR = currentXOR ^ nums[index]; //backtrack, we need to undo the change we made to the currentXOR variable when we included the current number in the XOR total, this will allow us to explore the next branch of the tree, which represents the subset that excludes the current number, and we can continue to explore all possible subsets of the nums array by recursively calling the backTrack function for each level of the tree
            }
            //say i = 1 is exclude
            if(i == 1){
                backTrack(nums, index + 1, currentXOR);
            }
        }
    }
    int subsetXORSum(vector<int>& nums) {
        backTrack(nums, 0, 0);
        return sum;
    }
};
// @lc code=end

