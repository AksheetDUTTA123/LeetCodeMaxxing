#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
public:
    void dfs(string currCity, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& res){ //thinking about doing some kind of recursive DFS here
        auto& dest = adj[currCity];

        while(!dest.empty()){
            auto top = dest.top();
            dest.pop();
            dfs(top, adj, res); //we take the destination with the highest priority (lexicographically smallest) and recursively call dfs on it, this will allow us to explore all of the destinations from the current city before we add the current city to the result vector
        }
        res.push_back(currCity);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto ticket : tickets){
            adj[ticket[0]].push(ticket[1]); //we made an adj list that maps the departure city to a min heap of arrival cities, so we can always get the lexicographically smallest arrival city first
        }
        dfs("JFK", adj, res); //kick off recursive DFS by starting with JFK
        reverse(res.begin(), res.end()); //the res vector will be in reverse order because we are pushing the cities onto the res vector after we have explored all of their neighbors, so we need to reverse the res vector to get the correct order of the itinerary
        //think about the recursive stack, when we reach a city that has no more neighbors to explore, we push it onto the res vector, and then we backtrack to the previous city and explore its neighbors, and when we reach a city that has no more neighbors to explore, we push it onto the res vector, and so on, until we have explored all of the cities in the itinerary, so the res vector will be in reverse order of the itinerary, so we need to reverse it to get the correct order of the itinerary
        return res;
    }
};
// @lc code=end

