#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //this is a deque problem, because maintain max value while being able to remove from front and back of deque
        deque<int> window;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(!window.empty() && window.front() <= i - k){
                window.pop_front(); //if index at front of the deque is out of the window  (i - k), remove from deque
            }
            while(!window.empty() && nums[window.back()] < nums[i]){
                window.pop_back(); //if current number is greater than the number at the back of the deque, remove the back of the deque, because it can never be the maximum if there is a greater number in the window
            }
            window.push_back(i); //store the index within the deque
            if(i >= k - 1){
                result.push_back(nums[window.front()]); //store the actual value within the answer vector
            }
        }
        return result;
    }
};
// @lc code=end

