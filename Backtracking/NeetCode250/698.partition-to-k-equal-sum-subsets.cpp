#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
//this question is very much like Matchsticks to square , we just need to check if we can fit the numbers into k subsets instead of 4 sides, 
//and we need to check if the sum of each subset is equal to the target sum, which is the total sum of the numbers divided by k, and we can use backtracking to try to fit the numbers into the subsets, 
//and if we can fit all the numbers into the subsets and reach the end of the numbers array, then we can return true, otherwise we can return false
class Solution {
public:
    bool backtracking(vector<int>& nums, int index, vector<int>& subsets, int target){
        if(index == nums.size()){ //if index is at the end of the numbers array, 
        //we have successfully fit all the numbers into the subsets, so we can return true, because we just need to check if we have successfully fit all the numbers into the subsets,
            return true;
        }

        for(int i = 0; i < subsets.size(); i++){
            if(nums[index] + subsets[i] <= target){
                subsets[i] += nums[index];
                
                if(backtracking(nums, index + 1, subsets, target)) return true; //move index up by one, check if we can fit the next number in the next recursive call,
                // and if we have successfully fit all the numbers in the subsets and reached the end of the numbers array, then we can return true, otherwise we can continue to try to fit the next number

                subsets[i] -= nums[index];
                if(subsets[i] == 0) break; //if we have tried to fit the current number in an empty subset and it didnt work,
                // then we know that there is no point in trying to fit the current number in another empty subset, because it will also not work, 
                //so we can break out of the loop and return false, this will allow us to efficiently find a solution if one exists, and if we try to fit the current number 
                //in another empty subset after trying it in the first empty subset, we will just be repeating the same process and it will lead to unnecessary backtracking and a longer runtime
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % k != 0) return false; //if not 0, cant be divided evenly into k subsets
        int target = totalSum / k;
        vector<int> subsets(k, 0); //need to create vector of size k to store the sum of each subset,
        // we will try to fit the numbers into these subsets and check if we can reach the target sum for each subset, if we can, then we can return true, otherwise we can return false
        sort(nums.rbegin(), nums.rend()); //sort because we want to try to fit the largest numbers first, 
        //this will allow us to quickly determine if a number is too large to fit in any of the subsets, and if it is, we can skip it and move on to the next number, 
        //this will allow us to efficiently find a solution if one exists, and if we try to fit the smaller numbers first, we may end up trying to fit a large number later 
        //on that cannot fit in any of the subsets, which will lead to unnecessary backtracking and a longer runtime
        return backtracking(nums, 0, subsets, target);

        
    }
};
// @lc code=end

