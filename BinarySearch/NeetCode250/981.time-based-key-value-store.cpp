#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
public:
    TimeMap() {
        //dont need to do anything here
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timeMap.find(key) == timeMap.end()){
            return "";
        }
        int left = 0;
        int right = timeMap[key].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(timeMap[key].at(mid).first == timestamp){
                return timeMap[key].at(mid).second;
            }
            else if(timeMap[key].at(mid).first < timestamp){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right >= 0 ? timeMap[key].at(right).second : "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

