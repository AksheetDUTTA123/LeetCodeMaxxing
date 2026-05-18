#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boatCt= 0;
        sort(people.begin(), people.end());
        int boatPtr1 = 0; //this can be the first member of the boat
        int boatPtr2 = people.size() - 1; //if below the limit, check the second to see if can be added in the boat
        while(boatPtr1 <= boatPtr2){
            if(people[boatPtr1] + people[boatPtr2] <= limit){
//                 Greedy logic: Always try to pair the heaviest person with the lightest.

                // If they fit together → both board, both pointers move inward
                // If they don't fit → heavy person goes alone, only heavy moves inward
                boatPtr1++; //The heaviest person is the hardest to pair. 
                //The best possible partner for them is the lightest person. 
                //If even the lightest person can't pair with them, nobody can — so they take a boat alone.
            }
            boatPtr2--;
            boatCt++;
        }
        return boatCt;

    }
};
// @lc code=end

