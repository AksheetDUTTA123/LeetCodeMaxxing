#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // //first method, do a minHeap
        // unordered_map<int, int> freq;
        // for(int num:nums){
        //     freq[num]++; //adding the frequency to each number in the map

        // }
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; //declare the minHeap, order is type, then container, then greater(minHeap) or less(maxHeap)
        // for(auto& [num, count] : freq){ //iterate thru the map
        //     minHeap.push({count, num}); //push the count and then the number into the minHeap, minHeap orders by first element of the pair, which is the count.
        //     if(minHeap.size() > k){ //over k, pop the smallest element, falls outside the top k
        //         minHeap.pop();
        //     }
        // }

        // vector<int> res;
        // while(!minHeap.empty()){ //go through the k elements
        //     res.push_back(minHeap.top().second); //push the second value, which is the actual number
        //     minHeap.pop();
        // }
        // return res;

        //second method, bucket sort
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++; //adding the frequency to each number in the map
        }
        vector<vector<int>> buckets(nums.size()+ 1); //make the buckets, the size is the size of the nums vector at worst case(frequency 1 for each number), and +1 because frequency is the index
        for(auto& [num, count] : freq){
            buckets[count].push_back(num); //push the number into the bucket associated with that count, which is what was found within the map
        }
        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0 && res.size() < k; i--){ //start from the end of buckets, as this is the highest frequency values, go down until k elements are found
            for(int num : buckets[i]){
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end

