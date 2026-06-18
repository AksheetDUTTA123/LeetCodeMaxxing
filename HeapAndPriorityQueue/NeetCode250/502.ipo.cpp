#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int currProjectNum = 0;
        vector<pair<int, int>> projects;
        for(int i = 0; i < profits.size(); i++){
            projects.push_back({capital[i], profits[i]}); //sort capitals from low to high, store as pairs
        }
    std::sort(projects.begin(), projects.end());
    priority_queue<int> pq; //store just profits, maxHeap so most progitable ones are popped and added first when able
    for(int i = 0; i < k; i++){ //max number of projects we can do is k, so loop k times to find best project at each step

        while(currProjectNum < projects.size() && projects[currProjectNum].first <= w){ //ensure we can index through projects and make sure the capital required for the project is less than or equal to our current capital, 
        //if it is, then we can add the profit of that project to the priority queue, and then we can move on to the next project,
            pq.push(projects[currProjectNum].second); //add the profit to maxHeap priority queue
            currProjectNum++; //increment projectNum to next project, want to see the next lowest capital project and if it is also less than or equal to our current capital, 
            //if it is, then we can add that profit to the priority queue as well, we want to add all projects that are less than or equal to our current capital to the priority queue,
        }
        
        if(pq.empty()) break;
        int best = pq.top(); //best available project that can be done with current capital, this is the project with the highest profit that we can do with our current capital, so we want to do this project first to maximize our capital for the next iteration,
        w += best;
        pq.pop();
    }

    return w;
    }


};
// @lc code=end

