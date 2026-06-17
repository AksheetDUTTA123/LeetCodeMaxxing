#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq; //need a maxHeap here, heaviest elements on top

        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x != y) pq.push(y - x);
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};
// @lc code=end

