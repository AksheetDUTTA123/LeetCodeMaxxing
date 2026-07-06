#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> numFreq; //using an ordered map to keep track of the frequency of each number 
        //in the hand, so we can always get the smallest number in the hand
        for(int i = 0; i < hand.size(); i++){
            numFreq[hand[i]]++;
        }
        while(!numFreq.empty()){
            int start = numFreq.begin()->first;
            for(int i = 0; i < groupSize; i++){
                int currCard = start + i; //we want to check if the current card is in the hand, 
                //if it is not, then we cannot form a group of consecutive cards, so we return false

                if(numFreq.find(currCard) == numFreq.end()) return false;

                numFreq[currCard]--;
                if(numFreq[currCard] == 0) numFreq.erase(currCard);

            }

        }
        return true;
    }
};
// @lc code=end

