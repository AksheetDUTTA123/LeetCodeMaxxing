#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
private:
    unordered_map<int, int> mapIndex;
    vector<int> nums;
public:
    RandomizedSet() {
        //alr initialize in the vector
    }
    
    bool insert(int val) {
        if(mapIndex.find(val) != mapIndex.end()){
            return false;
        }
        nums.push_back(val);
        mapIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mapIndex.find(val) == mapIndex.end()){
            return false;
        }
        if(nums.empty()) return false;
        int tempValIndex = mapIndex[val]; //this will get moved to the end of the vector
        int tempLastVal = mapIndex[nums[nums.size()- 1]]; //this is moved to the new index at tempValIndex
        int lastVal = nums[nums.size() - 1];
        std::swap(nums[tempValIndex], nums[nums.size() - 1]);
        mapIndex[lastVal] = tempValIndex;
        mapIndex.erase(val);
        nums.pop_back();
        return true;
        

    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

