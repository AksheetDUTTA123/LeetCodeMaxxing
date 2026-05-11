#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
public:
    MyHashSet() {
        //boolArr[1000001] = {false};
    }
    
    void add(int key) {
        boolArr[key] = true;
    }
    
    void remove(int key) {
        boolArr[key] = false;
    }
    
    bool contains(int key) {
        return boolArr[key];
    }

private:
bool boolArr[1000001] = {false};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

