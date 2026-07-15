#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1429 lang=cpp
 *
 * [1429] First Unique Number
 */

// @lc code=start
class FirstUnique {
    //commented code works, but it is amoritized O(1), a better way is to use a list and have iterators
private:
    // deque<int> uniqueNums;
    // unordered_set<int> uniqueCheck;
    // unordered_set<int> nonUniqueFound;
    std::list<int> uniqueNums;
    unordered_map<int, std::list<int>::iterator> uniqueCheck;
    unordered_set<int> nonUniqueFound;
public:
    FirstUnique(vector<int>& nums) {
    //     for(int i = 0; i < nums.size(); i++){
    //         if(uniqueCheck.find(nums[i]) == uniqueCheck.end()) {
    //             uniqueCheck.insert(nums[i]);
    //             uniqueNums.push_back(nums[i]);
    //     }
    //     else{
    //         nonUniqueFound.insert(nums[i]);
    //     }
    // }

            for(int num : nums) add(num);
    }
    
    int showFirstUnique() {
        // while(nonUniqueFound.find(uniqueNums.front()) != nonUniqueFound.end()){
        //     uniqueNums.pop_front();
        // }
        // if(uniqueNums.empty()) return -1;
        // return uniqueNums.front();
        if(uniqueNums.empty()) return -1;
        return uniqueNums.front();
    }
    
    void add(int value) {
        //  if(uniqueCheck.find(value) == uniqueCheck.end()) {
        //         uniqueCheck.insert(value);
        //         uniqueNums.push_back(value);
        // }
        // else{
        //     nonUniqueFound.insert(value);
        // }

        if(nonUniqueFound.find(value) != nonUniqueFound.end()){
            return;
        }

        if(uniqueCheck.find(value) == uniqueCheck.end()){
            uniqueNums.push_back(value);
            uniqueCheck[value] = --uniqueNums.end(); //store the iterator to the last element in the list
        }
        else{
            nonUniqueFound.insert(value);
            uniqueNums.erase(uniqueCheck[value]); //remove the element from the list using the iterator
            uniqueCheck.erase(value); //remove the element from the map
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
// @lc code=end

