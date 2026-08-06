#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        if(s.empty() || g.empty()) return 0;
        int satisfied = 0;
        int currCookieIdx = 0;
        int currChildIdx = 0;
        while(currChildIdx < g.size() && currCookieIdx < s.size()){
            if(s[currCookieIdx] >= g[currChildIdx]){
                currChildIdx++;
                currCookieIdx++;
                satisfied++;
            }
            else{
                currCookieIdx++;
            }
        }
        return satisfied;
    }
};
// @lc code=end

