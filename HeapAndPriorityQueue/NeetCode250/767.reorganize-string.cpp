#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string s) {
        string result = "";
        int count[26] = {0};

        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            if(count[s[i] - 'a'] > ((s.length() + 1)/ 2)) return "";
        }

        vector<pair<int, int>> charStor;
        for(int i = 0; i < 26; i++){
            charStor.push_back({i , count[i]});
        }

        auto comparator = [](const pair<int, int> p1, const pair<int, int> p2){
            return p1.second < p2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq;

        for(int i = 0; i < 26; i++){
            if(charStor[i].second > 0) pq.push(charStor[i]);
        }

        while(pq.size() >= 2){
            auto top = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            top.second--;
            second.second--;
            result += top.first + 'a';
            result += second.first + 'a';
            if(top.second > 0 ) pq.push(top);
            if(second.second > 0) pq.push(second);
        }

        if(pq.size() == 1){
            auto top = pq.top();
            pq.pop();
            top.second--;
            result += top.first + 'a';
            if(top.second > 0) return "";
        }
        return result;

    }
};
// @lc code=end

