#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int longestFruit = 0;
        int start = 0;
        int end = 0;
        int currFruit = 0;
        unordered_map<int, int> fruit;
        for(int i = 0; i < fruits.size(); i++){
        fruit[fruits[i]]++;
        end++;
           if(fruit.size() > 2){
            while(fruit.size() != 2){
                fruit[fruits[start]]--;
                if(fruit[fruits[start]] == 0) fruit.erase(fruits[start]);
                start++;
            }
           }
           longestFruit = max(longestFruit, i - start + 1);
        }
        return longestFruit;
    }
};
// @lc code=end

