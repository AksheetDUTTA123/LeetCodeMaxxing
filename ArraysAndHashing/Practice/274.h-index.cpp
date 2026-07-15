#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        //we are not trying to find the median here, because the median is the middle value of a sorted list, and we are trying to find the maximum h-index, which is the maximum number of papers that have at least h citations. The median does not give us this information, because it only tells us the middle value of the sorted list, and does not tell us how many papers have at least that many citations. We need to find the maximum h-index,
        /// which is the maximum number of papers that have at least h citations, so we need to iterate through the sorted list and find the maximum value of citations[i] such that citations[i] >= citations.size() - i.
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >= citations.size() - i){
                return citations.size() - i; //citation count is the number of papers remaining from i, this is because we want to find the maximum h-index, 
                //which is the maximum number of papers that have at least h citations. The number of papers remaining from i is the number of papers that have at least citations[i] citations, so we return that value as the h-index
            }
        }
        return 0;
    }
};
// @lc code=end

