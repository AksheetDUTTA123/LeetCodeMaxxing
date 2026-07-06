#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1871 lang=cpp
 *
 * [1871] Jump Game VII
 */

// @lc code=start
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // vector<bool> dp(s.length(), false);

        // dp[0] = true;

        // for(int i = 1; i < s.length(); i++){
        //     if(s[i] != '0' || dp[i] != true) continue; 
        //     for(int j = i + minJump; j <= (min((int) s.length() - 1, i + maxJump)); j++){
        //         if(s[j] == '0') dp[j] = true;
        //     }
        // }


        // return dp[s.length() - 1];

        queue<int> q;
        int furthest = 0;

        q.push(0);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            if(curr == s.length() - 1) return true;

            int start = max(curr + minJump, furthest + 1); //we start from the maximum of the current index plus the minimum jump and the 
            //furthest index we have reached so far plus one. This ensures that we do not revisit indices that we have already processed, which helps to optimize the algorithm and avoid unnecessary computations.
            int end = min((int)s.length() - 1, curr + maxJump); //we end at the minimum of the last index of the string and the 
            //current index plus the maximum jump. This ensures that we do not go out of bounds of the string while checking for reachable indices.

            for (int i = start; i <= end; i++){
                if(s[i] == '0') q.push(i);
                furthest = max(i, furthest); //we update the furthest index we have reached so far to be the maximum of the current index and the previous furthest index. 
                //This helps to keep track of the furthest point we can reach in the string, which is important for determining if we can reach the last index.
            }
        }
        return false;

    }
};
// @lc code=end

