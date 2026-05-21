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
        //the trick is that you are binary searching the eating speed, not the piles
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()); //max element returns the pointer, dereference ptr to get the value
        int answer = right;
        while(left < right){
            int mid = left + (right - left)/2; //eating speed can be between 1 and max of the piles, so we can binary search between those two values to find the minimum eating speed that allows Koko to finish eating all the bananas within h hours.
            int hoursNeeded = 0;
            for(int p:piles){
                hoursNeeded += (p + mid - 1) / mid; //the (p + mid - 1) / mid is a common way to calculate the ceiling of p/mid without using floating point division. It works by adding mid - 1 to p before dividing by mid, which effectively rounds up the division result when p is not perfectly divisible by mid.
            }
            if(hoursNeeded <= h){
                answer = mid; //not hoursneeded, we need to return the minimum eating speed, so if hours needed is less than or equal to h, we can try to find a smaller eating speed, so we set right to mid. If hours needed is greater than h, we need to increase the eating speed, so we set left to mid + 1.
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return answer;
    }
};
// @lc code=end

