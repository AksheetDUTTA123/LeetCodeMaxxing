#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        //have a vector to store num of candies each child gets, start with 1
        vector<int> candies(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){ //do a left to right pass, if current rating is greater than previous rating,
        // give current child 1 more candy than previous child
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){ //do a right to left pass, if current rating is greater than next rating,
            // give current child 1 more candy than next child, but also take the max of the current candy count and the new candy count, because we want to make sure we are not giving less candies than we already have given in the left to right pass
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        int totalCandies = 0;
        for(int c : candies){
            totalCandies += c;
        }
        return totalCandies;
    }
};
// @lc code=end

