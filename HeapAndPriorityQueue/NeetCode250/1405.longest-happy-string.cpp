#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto comparator = [](const pair<char, int>& p1, const pair<char, int>& p2){
            return p1.second < p2.second;
        };

        std::priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comparator)> pq;

        vector<pair<char, int>> charStor;
        if (a > 0) pq.push({'a', a});
        if (b > 0) pq.push({'b', b});
        if (c > 0) pq.push({'c', c});
        string res = "";

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int n = res.size();
            if (n >= 2 && res[n - 1] == top.first && res[n - 2] == top.first) {
                    //we cannot use the most frequent character here
                if(pq.empty()) break; // no other choice


                auto nextTop = pq.top();
                pq.pop();

                res += nextTop.first;
                nextTop.second--;

                if(nextTop.second > 0) pq.push(nextTop);
                pq.push(top);
        }
        else{
            //we can use the most frequent character here

            res += top.first;
            top.second--;
            if(top.second > 0){
                pq.push(top);
            }
        }
        }
        return res;
    }
};
// @lc code=end

