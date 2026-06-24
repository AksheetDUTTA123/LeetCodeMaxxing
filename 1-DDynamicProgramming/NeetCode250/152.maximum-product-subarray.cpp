#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int result = nums[0];
        int minSoFar = nums[0];
        int maxSoFar = nums[0];


        for(int i = 1; i < nums.size(); i++){
            int tempmaxSoFar = max(nums[i], max(maxSoFar * nums[i] , minSoFar * nums[i])); //find the max of the current number, the max product so far times the current number, and the min product so far times the current number. It is possible that the current number itself is the max product, or that the max product so far times 
            //the current number is the max product, or that the min product so far times the current number is the max product. We have to keep track of both the min and max products because if we multiply a negative number by a negative number, we can get a positive number that is larger than the max product so far.
            minSoFar = min(nums[i], min(maxSoFar * nums[i] , minSoFar * nums[i])); // find the min of the current number, the max product so far times the current number, and the min product so far times the current number. It is possible that the current number itself is the min product, or that the max product so far times. It is possible the minNumber times a negative number is the min product, or that the min product so far times the current number is the min product. 
            //We have to keep track of both the min and max products because if we multiply a negative number by a negative number, we can get a positive number that is larger than the max product so far.
            maxSoFar = tempmaxSoFar;
            result = max(result, maxSoFar);
        }
        return result;
    }
};
// @lc code=end

