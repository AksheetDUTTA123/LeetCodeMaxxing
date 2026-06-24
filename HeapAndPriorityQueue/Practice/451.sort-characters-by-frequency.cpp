#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        
        string res = "";
        auto comparator = [](pair<int, char> p1, pair<int, char> p2){
            return p1.first < p2.first;
        };

        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comparator)> pq;


        unordered_map<char, int> freqCt;
        for(char c : s) freqCt[c]++;
        for(auto pair:freqCt){
            pq.push({pair.second, pair.first});
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            while(top.first > 0){
                res += top.second;
                top.first--;
            }
        }
        return res;
    }
};
// @lc code=end

