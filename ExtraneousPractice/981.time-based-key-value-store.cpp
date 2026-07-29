#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
private: 
        unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = mp[key].size() - 1;
        string res = "";
        while(low <= high){
            int mid = low + ((high - low)/2);
            
            if(mp[key][mid].first <= timestamp){
                res = mp[key][mid].second;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

