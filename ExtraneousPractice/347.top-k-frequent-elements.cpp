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
        unordered_map<int, int> freqCt;
        int maxFreq  =0;
        for(int num : nums){
            freqCt[num]++;
            if(freqCt[num] > maxFreq) maxFreq = freqCt[num];
        }

        vector<vector<int>> buckets(maxFreq + 1);

        for(auto &[num, freq] : freqCt){
            buckets[freq].push_back(num);
        }
        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0 && res.size() < k; i--){
            for(int num : buckets[i]){
                res.push_back(num);
                if(res.size() == k) break;
            }
        }
        return res;
    }
};
// @lc code=end

