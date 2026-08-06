#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3843 lang=cpp
 *
 * [3843] First Element with Unique Frequency
 */

// @lc code=start
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freqCt;
        for(int num : nums){
            freqCt[num]++;
        }
        unordered_map<int, int> freqoffreq;
        for(auto& [num, count] : freqCt){
            freqoffreq[count]++;
        }

        for(int i = 0; i < nums.size(); i++){
            if(freqoffreq[freqCt[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};
// @lc code=end

