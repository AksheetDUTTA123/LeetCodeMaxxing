#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
private:
void dfs(string currCity, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& res){
    auto& dest = adj[currCity];
    while(!dest.empty()){
        auto top = dest.top();
        dest.pop();
        dfs(top, adj, res);
    }
    res.push_back(currCity);
}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        vector<string> res;
        for(auto ticket : tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

