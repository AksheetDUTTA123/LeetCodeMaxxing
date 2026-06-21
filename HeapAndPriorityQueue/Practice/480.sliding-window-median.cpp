#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> low;
        multiset<int> high;


        //first step, remove element that gets removed
        for(int i = 0; i < nums.size(); i++){
            if(i >= k){ //scenario when we do have to remove an elem
                if(nums[i - k] <= *low.rbegin()){ //less than the largest num in low
                    low.erase(low.find(nums[i-k]));
                }
                else{
                    high.erase(high.find(nums[i-k]));
                }

            }

        low.insert(nums[i]); //insert to min heap


        high.insert(*low.rbegin()); //move highest elem in low to high heap
        low.erase(prev(low.end())); //remove the elem from low heap

        while(low.size() < high.size()){ //rebalancing heap size here like in 295 (minHeap.size > maxHeap.size())
            low.insert(*high.begin());
            high.erase(high.begin());
        }

        //now have to find the median 


        if(i >= k - 1){
            if(k % 2 == 1){
                res.push_back(*low.rbegin());
            }
            else{
                double result = (double) (((double)*low.rbegin() + *high.begin()) * 0.5);
                res.push_back(result);
            }
        }
    }
 return res;
    }
};
// @lc code=end

