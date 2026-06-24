#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
private:
    vector<string> res;
public:
    void backtracking(string& s, int startIdx, int segments, string& curr){
        if(startIdx == s.length() && segments==4){
            res.push_back(curr);
            return;
        }

        if(startIdx == s.length() || segments==4){
            return;
        }
        int oldSize = curr.size(); //save old size before the backtracking occurs
        for(int i = 1; i < 4; i++){
            if(startIdx + i > s.length()) return;
            string testSeg = s.substr(startIdx, i);
            if(testSeg.length() > 1 && testSeg[0] == '0') break;
            if(stoi(testSeg) > 255) break;
            if(segments == 0){
                curr += testSeg;
            }
            else{
                curr += '.' + testSeg;
            }
            backtracking(s, startIdx + i, segments + 1, curr);
            curr.resize(oldSize); //undo back to old size, use resize here

        }

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length() < 4 || s.length() > 12) return res;
        string curr = "";
        backtracking(s, 0, 0, curr);
        return res;
    }
};
// @lc code=end

