#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=277 lang=cpp
 *
 * [277] Find the Celebrity
 */

// @lc code=start
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // vector<int> degreeCt(n + 1, 0);

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i ==j) continue;
        //         if(knows(i, j)){
        //             degreeCt[i]++;
        //             degreeCt[j]--;
        //         }
        //     }
        // }
        // for(int i = 0; i < degreeCt.size(); i++){
        //     if(degreeCt[i] == -(n - 1)) return i;
        // }
        // return -1;
        

        //there is a better way to do this

        int candidate = 0;
        for(int i = 0; i < n; i++){
            if(knows(candidate, i)){
                candidate = i; //candidate knows i, so update candidate to new possible one
            }
        }
        for(int i = 0; i < n; i++){
            if (candidate == i) continue;
            if(knows(candidate, i) || !knows(i, candidate)) return -1;
        }
        return candidate;
    }
};
// @lc code=end

