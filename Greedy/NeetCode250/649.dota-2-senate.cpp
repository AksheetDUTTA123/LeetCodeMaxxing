#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R; //queue for radiant senators, store their indices
        queue<int> D;//queue for dire senators, store their indices

        for(int i = 0; i < senate.length(); i++){
            if(senate[i] == 'R') R.push(i);
            else D.push(i);
        }

        while(!R.empty() && !D.empty()){
            int Ridx = R.front(); //we take the first senator from each queue
            R.pop();
            int Didx = D.front();
            D.pop();

            if(Ridx > Didx){ //if the radiant senator comes after the dire senator, the dire senator bans the radiant senator, and then the dire senator goes to the back of the queue
            //goes to the back of the queue with an index that is incremented by the length of the senate string, so that it will come after all the current senators in the queue, this is because 
            //the senators are in a circular arrangement, and we want to simulate the next round of voting
                D.push(Didx + senate.length());
            }
            else{
                R.push(Ridx + senate.length());
            }
        }

        if(R.empty()) return "Dire"; //if the radiant queue is empty, then the dire senators have won
        else return "Radiant";

    }
};
// @lc code=end

