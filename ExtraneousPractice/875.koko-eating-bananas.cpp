#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //in this question we have to binary search over an answer space
        int max = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > max) max = piles[i];
        }
        int left = 1;
        int right = max;
        int bestRes = 0;
        while(left <= right){
            int mid = left + ((right - left) / 2);
            long long currHrs = 0;
            for(int i = 0; i < piles.size(); i++){
                currHrs += ceil((piles[i] + mid - 1) / mid);
            }
            if(currHrs <= h){
                bestRes = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return bestRes;
    }
};
// @lc code=end

