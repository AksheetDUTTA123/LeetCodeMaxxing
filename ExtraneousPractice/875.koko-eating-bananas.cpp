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
        //the binary search range will be from 1 to max of piles;

        int right = *std::max_element(piles.begin(), piles.end());
        long long hrCt = 0;
        int left = 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            hrCt = 0;
            for(int i = 0; i < piles.size(); i++){
                hrCt += ceil((double)piles[i] / mid);
            }
            if(hrCt <= h){
                right = mid ;
            }
            else{
                left = mid + 1;
            }


        }
        return left;
    }
};
// @lc code=end

