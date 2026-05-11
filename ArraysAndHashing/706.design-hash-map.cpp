#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        arr[key] = {true, value};
    }
    
    int get(int key) {
        if(arr[key].first == false) return -1;
        return arr[key].second;
    }
    
    void remove(int key) {
        arr[key] = {false, -1};
    }

private:
std::pair<bool, int> arr[1000001] = {{false, -1}};
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

