#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1244 lang=cpp
 *
 * [1244] Design A Leaderboard
 */

// @lc code=start
class Leaderboard {
private:
unordered_map<int, int> leaderboard;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(leaderboard.find(playerId) == leaderboard.end()){
            leaderboard.insert({playerId, score});
        }
        else{
            leaderboard[playerId] += score;
        }
    }
    
    int top(int K) {
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto elem : leaderboard){
            pq.push(elem.second);
            if(pq.size() > K) pq.pop();
        }
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
    
    void reset(int playerId) {
        leaderboard.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
// @lc code=end

