#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        
        for(string s : deadends) visited.insert(s);
        if(visited.find("0000") != visited.end()) return -1;
        queue<pair<string, int>> q; //int is the number of moves needed to reach that combo
        q.push({"0000", 0});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            string currCombo = top.first;
            int currMoves = top.second;
            if(top.first == target) return top.second;
            for(int i = 0; i < 4; i++){
                for(int delta : {-1, 1}){ // we move by 1 digit up/down
                    int newDigit = (currCombo[i] - '0' + delta + 10) % 10; //need the + 10 so -1 becomes a 9
                    string newCombo = currCombo;
                    newCombo[i] = '0' + newDigit;

                    if(visited.find(newCombo) == visited.end()){
                        visited.insert(newCombo);
                        q.push({newCombo, currMoves + 1});
                    }

                }
            }


        }
        return -1;




    }
};
// @lc code=end

