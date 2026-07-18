#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }
        while (k > 0){
            auto top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
            k--;
        }
        long long res = 0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

