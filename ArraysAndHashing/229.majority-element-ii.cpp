#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> totalVals(2);// 2 majority numbers tops 
        int count1 = 0;
        int count2 = 0;
        totalVals[0] = -1*10^10; //set as val that cannot be reached
        totalVals[1] = -1*10^10;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == totalVals[0]){
                count1++; // if same as first majority number, incremenent counter
            }
            else if(nums[i] == totalVals[1]){
                count2++; // if same as second majority number, incremenent counter
            }
            else{
                if(count1 == 0){
                    totalVals[0] = nums[i]; //if not the same and counter at 0, we know this is not the majority number, so replace with new number and reset counter
                    count1 = 1; 
                }
                else if(count2 == 0){
                    totalVals[1] = nums[i]; //if not the same and counter at 0, we know this is not the majority number, so replace with new number and reset counter
                    count2 = 1;
                }
                else{
                    count1--; //this is the trick, if we find a number that is not the same as either majority number, we know this number is not the majority number, so we have to decrement both counters
                    count2--;
                }
            }
        }

        //beginning of second pass
        int totalCount1= 0; //set counter for totalVals 0
        int totalCount2 = 0;//set counter for totalVals 1
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == totalVals[0]){
                totalCount1++; //if totalVals 0 found, increment ctr
            }
            else if (nums[i] == totalVals[1]){
                totalCount2++; //if totalVals 1 found, increment ctr
            }
        }
        if(totalCount2 <= nums.size() /3){
            totalVals.erase(totalVals.begin() + 1); //if totalVals 1 not majority, remove from vector. Start from end to avoid index issues
        }
        if(totalCount1 <= nums.size() /3){
            totalVals.erase(totalVals.begin()); //if totalVals 0 not majority, remove from vector.
        }
        return totalVals;
    }
};
// @lc code=end

