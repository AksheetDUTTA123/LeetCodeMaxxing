#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3885 lang=cpp
 *
 * [3885] Design Event Manager
 */

// @lc code=start
struct EventComparator {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[1] == b[1]) return a[0] > b[0]; 
        return a[1] < b[1];                   
    }
};

class EventManager {
private:
    priority_queue<vector<int>, vector<vector<int>>, EventComparator> pq;
    unordered_map<int, int> newPrior;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto event : events){
            pq.push({event[0], event[1]});
            newPrior[event[0]] = event[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        newPrior[eventId] = newPriority;
        pq.push({eventId, newPriority});
    }
    
    int pollHighest() {
        if(pq.empty()) return -1;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if (newPrior.find(top[0]) != newPrior.end() && newPrior[top[0]] == top[1]){
                newPrior.erase(top[0]);
                return top[0];
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
// @lc code=end

